<?php


/**
 * @file
 * Theme and preprocess functions for commerce_product.
 */

function ea_preprocess_commerce_product(&$variables) {
  if ($variables['elements']['#view_mode'] == 'teaser') {
    $variables['product']['variation_price']['#access'] = FALSE;
  }
}
