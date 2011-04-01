<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function dr_campaign_user_default_permissions() {
  $permissions = array();

  // Exported permission: create campaign content
  $permissions['create campaign content'] = array(
    'name' => 'create campaign content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'campaign coordinator',
    ),
  );

  // Exported permission: delete any campaign content
  $permissions['delete any campaign content'] = array(
    'name' => 'delete any campaign content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own campaign content
  $permissions['delete own campaign content'] = array(
    'name' => 'delete own campaign content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'campaign coordinator',
    ),
  );

  // Exported permission: edit any campaign content
  $permissions['edit any campaign content'] = array(
    'name' => 'edit any campaign content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'campaign coordinator',
    ),
  );

  // Exported permission: edit own campaign content
  $permissions['edit own campaign content'] = array(
    'name' => 'edit own campaign content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'campaign coordinator',
    ),
  );

  return $permissions;
}
