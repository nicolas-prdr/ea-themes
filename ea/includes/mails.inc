<?php

use Drupal\Core\Url;

/**
 * Implements hook_preprocess_HOOK().
 */
function ea_preprocess_swiftmailer(&$variables) {
  /** @var \Drupal\Core\Extension\ThemeHandlerInterface */
  $themeHandler = \Drupal::service('theme_handler');
  $default_theme = $themeHandler->getDefault();
  $conf = \Drupal::config($default_theme . '.settings');
  $logo_csettings = $conf->get('logo');
  if ($logo_csettings['use_default']) {;
    $themePath = $themeHandler->getTheme($themeHandler->getDefault())->getPath();
    $variables['logo_url'] = Url::fromUserInput('/' . $themePath . '/logo.png', ['absolute' => TRUE])
      ->toString();
  } else {
    $variables['logo_url'] = file_create_url($logo_csettings['path']);
  }
}
