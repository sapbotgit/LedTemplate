from flask import Flask, render_template, request
from rpi_ws281x import PixelStrip, Color

app = Flask(__name__)

# Настройки ленты WS2812
LED_COUNT = 60  # Количество светодиодов на ленте
LED_PIN = 18  # GPIO пин, к которому подключена лента
LED_FREQ_HZ = 800000  # Частота обновления ленты (обычно 800kHz)
LED_DMA = 10  # Канал DMA для обновления (обычно 10)
LED_BRIGHTNESS = 255  # Яркость светодиодов (от 0 до 255)
LED_INVERT = False  # Инвертирование сигнала данных (True или False)

# Создаем экземпляр PixelStrip
strip = PixelStrip(LED_COUNT, LED_PIN, LED_FREQ_HZ, LED_DMA, LED_INVERT, LED_BRIGHTNESS)
strip.begin()

# Определение эффектов
effects = {
    1: "Эффект 1",
    2: "Эффект 2",
    3: "Эффект 3"
}

# Главная страница
@app.route('/')
def index():
    return render_template('index.html', effects=effects)

# Обработка выбора эффекта
@app.route('/effect', methods=['POST'])
def effect():
    choice = int(request.form['effect'])
    
    if choice == 1:
        # Ваш код для эффекта 1
        strip.setPixelColor(0, Color(255, 0, 0))  # Устанавливаем цвет первого светодиода
        strip.show()  # Применяем изменения к ленте
    elif choice == 2:
        # Ваш код для эффекта 2
        strip.setPixelColor(0, Color(0, 255, 0))  # Устанавливаем цвет первого светодиода
        strip.show()  # Применяем изменения к ленте
    elif choice == 3:
        # Ваш код для эффекта 3
        strip.setPixelColor(0, Color(0, 0, 255))  # Устанавливаем цвет первого светодиода
        strip.show()  # Применяем изменения к ленте
    
    return 'OK'

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
