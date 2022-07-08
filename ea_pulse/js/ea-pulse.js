/**
 * @file
 * EA Pulse behaviors.
 */

(function ($, Drupal) {
  "use strict";

  /**
   * Behavior description.
   */
  Drupal.behaviors.eaPulse = {
    attach: function (context, settings) {
      // console.log("EA Pulse main script.");
    },
  };

  const rangeTemperature = document.querySelector('.range-temperature')
  if(rangeTemperature) {
    const output = document.querySelector('#userTemperature')
    let rangeTemperatureValue = rangeTemperature.value
    rangeTemperature.addEventListener('input', () => {
      rangeTemperatureValue = rangeTemperature.value
      if(rangeTemperatureValue >= 38) {
        output.classList.add('is-red')
      } else {
        output.classList.remove('is-red')
      }
    })
  }

  const rangePain = document.querySelector('.range-pain')
  if(rangePain) {
    const output = document.querySelector('#userTemperature')
    let rangePainValue = rangePain.value
    rangePain.addEventListener('input', () => {
      rangePainValue = rangePain.value
      if(rangePainValue >= 5) {
        output.classList.add('is-red')
      } else {
        output.classList.remove('is-red')
      }
    })
  }

  const lastStep = document.querySelector('.progress-step[title="Complete"]')
  if(lastStep) {
    lastStep.remove()
  }

  const estimateForm = document.querySelector('#edit-estimate')
  if(estimateForm) {
    const items = estimateForm.querySelectorAll('.form-item')
    items.forEach(item => {
      item.addEventListener('click', () => {
        let isActive = estimateForm.querySelector('.form-item.is-active')
        item.classList.add('is-active')
        isActive ? isActive.classList.remove('is-active') : 'ok'
      })
    })
  }
})(jQuery, Drupal);
