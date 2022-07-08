<?php

use Drupal\Core\Template\Attribute;

/**
 * @file
 * Theme and preprocess functions for breadcrumb.
 */

function ea_preprocess_breadcrumb(&$variables) {
  if ($variables['breadcrumb']) {
    $request = \Drupal::request();
    $route_match = \Drupal::routeMatch();
    $page_title = \Drupal::service('title_resolver')->getTitle($request, $route_match->getRouteObject());

    if (!empty($page_title)) {
      $variables['breadcrumb'][] = [
        'text' => $page_title,
        'attributes' => new Attribute(['class' => ['active']])
      ];
    }
  }
}
