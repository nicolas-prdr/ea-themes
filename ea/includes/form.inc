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
function ea_theme_suggestions_input_alter(array &$suggestions, array $variables) {
  if (!empty($variables['element']['#symptom_checker'])) {
    $suggestions[] = 'input__submit__symptom_checker';
  }
}

/**
 * Implements hook_preprocess_input().
 */
function ea_preprocess_input(&$variables) {
  $element = $variables['element'];
  if ($element['#type'] == 'submit') {
    if (isset($element['#button_type'])) {
      $variables['type'] = $element['#button_type'];
    } else {
      $variables['type'] = 'primary';
    }

    // Si un picto du symptom checker est à afficher
    if (!empty($variables['element']['#symptom_checker'])) {
      $sub_dir = '/assets/images/symptom-checker/answer/';
      $path = drupal_get_path('theme', 'ea');
      $filename = $variables['element']['#name'] . '.svg';
      $uri = $path . $sub_dir . $filename;
      if (file_exists($uri)) {
        $variables['picto'] = [
          '#theme' => 'image',
          '#uri' => $path . $sub_dir . $filename,
          '#alt' => t('Illustration picture')
        ];
      }
      $variables['iput_target_id'] = $variables['attributes']['id'];
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ea_form_ea_eligibility_eligibility_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id) {

  $form['default']['picto'] = [
    '#type' => 'html_tag',
    '#tag' => 'img',
    '#attributes' => [
      'src' => 'themes/custom/ea/assets/images/step-2/welcome.svg',
      'class' => [
        'img-fluid',
        'd-block',
        'mx-auto',
        'mb-4'
      ]
    ]
  ];
}
/**
 * Implements hook_form_FORM_ID_alter().
 */
function ea_form_webform_submission_customer_info_add_form_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id) {
  $form['actions']['#attributes']['class'][] = 'd-grid';
  $form['actions']['#attributes']['class'][] = 'gap-2';
  $form['actions']['#attributes']['class'][] = 'pt-2';
}
