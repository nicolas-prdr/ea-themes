<?php

/**
 * @file
 * Theme and preprocess functions for blocks.
 */

use Drupal\block_content\BlockContentInterface;

/**
 * Implements hook_preprocess_HOOK().
 */
function ea_preprocess_block(&$variables) {

  /** @var BlockContentInterface */
  if (isset($variables['content']['#block_content'])) {
    $block = $variables['content']['#block_content'];
    if ($block->bundle() == 'country_selection') {

      if ($block->get('body')->summary) {
        $variables['content']['summary'] = $block->body->view([
          'label' => 'hidden',
          'type' => 'text_trimmed',
          'settings' => [
            'trim_length' => 130
          ]
        ]);
      }
      // pbm d'invalidation du cache, on le force donc ici.
      $variables['#cache']['tags'][] = 'block_content:' . $block->id();
    }
  }
}
