<?php

use Drupal\commerce_checkout\CheckoutOrderManagerInterface;
use Drupal\Component\Utility\Html;

/**
 * Implements hook_preprocess_HOOK().
 */
function ea_preprocess_page(&$variables) {

  $variables['attributes']['class'][] = 'page';
  if (\Drupal::routeMatch()->getRouteName() == 'commerce_checkout.form') {

    /** @var \Drupal\commerce_order\Entity\OrderInterface $order */
    $order = \Drupal::routeMatch()->getParameter('commerce_order');
    $requested_step_id = \Drupal::routeMatch()->getParameter('step');
    /**
     * @var CheckoutOrderManagerInterface
     */
    $checkoutOrderManager = \Drupal::service('commerce_checkout.checkout_order_manager');
    $step_id = $checkoutOrderManager->getCheckoutStepId($order, $requested_step_id);
    $variables['attributes']['class'][] = 'checkout-form';
    $variables['attributes']['class'][] = Html::cleanCssIdentifier('checkout-form--' . $step_id);
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ea_preprocess_page_title(&$variables) {

  // On met 'Checkout' comme unique titre sur toutes les pages de checkout.
  $route = \Drupal::routeMatch()->getRouteName();
  if ($route == 'commerce_checkout.form') {
    $variables['title'] = t('Checkout');
    $variables['title_attributes']['class'] = ['pb-3'];
  }
  if ($route == 'ea_livehelp.launcher') {
    $variables['title_attributes']['class'] = ['pb-3'];
  }
}
