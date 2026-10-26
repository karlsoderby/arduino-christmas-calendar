const ui = new WebUI();
const statusEl = document.querySelector('#status');
const temperatureEl = document.querySelector('#temperature');
const humidityEl = document.querySelector('#humidity');
const moodIcon = document.querySelector('#mood-icon');
const moodText = document.querySelector('#mood-text');

ui.on_connect(() => {
  statusEl.textContent = 'Connected';
  statusEl.classList.add('online');
});

ui.on_disconnect(() => {
  statusEl.textContent = 'Disconnected';
  statusEl.classList.remove('online');
});

ui.on_message('thermo', (data) => {
  temperatureEl.textContent = data.temperature.toFixed(1);
  humidityEl.textContent = data.humidity.toFixed(0);

  if (data.temperature < 2) {
    moodIcon.textContent = '☃️';
    moodText.textContent = 'Freezing! Perfect weather for a snowman.';
  } else if (data.temperature < 18) {
    moodIcon.textContent = '🧤';
    moodText.textContent = 'Chilly. Time for mittens and hot cocoa.';
  } else if (data.temperature < 24) {
    moodIcon.textContent = '🎄';
    moodText.textContent = 'Cozy! Just right for wrapping presents.';
  } else {
    moodIcon.textContent = '🔥';
    moodText.textContent = 'Toasty! Are you sitting by the fireplace?';
  }
});
