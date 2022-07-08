<?php

/**
 * Implements hook_preprocess_HOOK().
 */
function ea_preprocess_html(&$variables) {

  if (\Drupal::routeMatch()->getRouteName() == 'commerce_checkout.form') {
    $variables['attributes']['class'][] = 'body--checkout-form';
  }
}
