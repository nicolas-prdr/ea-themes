<?php

/**
 * @file
 * Theme and preprocess functions for forms.
 */

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 *
 * Création d'un template spécifique pour wrapper les <input type="submit">
 * dans un label cliquable.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ea_fiatc_form_ea_eligibility_eligibility_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id) {

  $form['default']['picto'] = [
    '#type' => 'html_tag',
    '#tag' => 'img',
    '#attributes' => [
      'src' => 'themes/custom/ea_fiatc/images/welcome-image.jpg',
      'class' => [
        'img-fluid',
        'd-block',
        'mx-auto',
        'mb-4'
      ]
    ]
  ];
}
