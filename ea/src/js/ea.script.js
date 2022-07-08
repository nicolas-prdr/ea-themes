import './_bootstrap.js';

(function ($, Drupal) {

  'use strict';

  // // Enable Bootstrap Popover sitewide.
  // // Popovers are opt-in for performance reasons.
  // Drupal.behaviors.bsPopover = {
  //   attach: function (context) {
  //     $('[data-bs-toggle="popover"]').popover();
  //   }
  // };

  // // Enable Bootstrap Toast sitewide.
  // // Toasts are opt-in for performance reasons.
  // Drupal.behaviors.bsToast = {
  //   attach: function (context) {
  //     $('.toast').toast('show');
  //   }
  // };

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

  const radioWrapper = document.querySelector('.form-radios')
  if(radioWrapper) {
    const radioItems = radioWrapper.querySelectorAll('.webform-options-display-buttons-wrapper')
    radioItems.forEach(item => {
      item.addEventListener('click', () => {
        let isActive = radioWrapper.querySelector('.webform-options-display-buttons-wrapper.is-active')
        isActive ? isActive.classList.remove('is-active') : 'ok'
        item.classList.add('is-active')
      })
    })
  }

})(jQuery, Drupal);
