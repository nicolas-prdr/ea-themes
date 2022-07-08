<?php

function ea_preprocess_commerce_checkout_pane(&$variables) {
  $elts = $variables['elements'];
  if (isset($elts['returning_customer']) && isset($elts['guest'])) {
    $variables['elements']['guest']['#weight'] = -1;
    $variables['elements']['returning_customer']['#weight'] = 0;
    $variables['elements']['#sorted'] = FALSE;
  }
}
