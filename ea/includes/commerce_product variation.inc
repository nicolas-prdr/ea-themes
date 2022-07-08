<?php

function ea_preprocess_commerce_product_variation(&$variables) {

  /** @var \Drupal\commerce_product\Entity\ProductVariationInterface */
  $product_variation = $variables['elements']['#commerce_product_variation'];
  $variables['title'] = $product_variation->label();
}
