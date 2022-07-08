<?php

function ea_pulse_form_system_theme_settings_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }
  $form['clinic_settings'] = [
    '#type' => 'details',
    '#title' => t('Clinic map pins'),
    '#open' => TRUE,
  ];

  $default_red_icon_url = "https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-2x-red.png";
  $form['clinic_settings']['ea_red_icon_url'] = [
    '#type' => 'textfield',
    '#title' => t('Red icon url'),
    '#default_value' => theme_get_setting('ea_red_icon_url') ?? $default_red_icon_url,
  ];

  $default_red_icon_shadow_url = "https://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.7/images/marker-shadow.png";
  $form['clinic_settings']['ea_red_icon_shadow_url'] = [
    '#type' => 'textfield',
    '#title' => t('Red icon shadow url'),
    '#default_value' => theme_get_setting('ea_red_icon_shadow_url') ?? $default_red_icon_shadow_url,
  ];

  $default_red_icon_shadow_url = "https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-2x-black.png";
  $form['clinic_settings']['ea_grey_icon_url'] = [
    '#type' => 'textfield',
    '#title' => t('Red icon url'),
    '#default_value' => theme_get_setting('ea_grey_icon_url') ?? $default_red_icon_shadow_url,
  ];

  $default_grey_icon_shadow_url = "https://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.7/images/marker-shadow.png";
  $form['clinic_settings']['ea_grey_icon_shadow_url'] = [
    '#type' => 'textfield',
    '#title' => t('Red icon shadow url'),
    '#default_value' => theme_get_setting('ea_grey_icon_shadow_url') ?? $default_grey_icon_shadow_url,
  ];
}
