<?php
/**
 * @file
 * volunteer_rule_switch.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function volunteer_rule_switch_default_rules_configuration() {
  $items = array();
  $items['rules_add_volunteer_on_update'] = entity_import('rules_config', '{ "rules_add_volunteer_on_update" : {
      "LABEL" : "Add Volunteer On Update",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "text_matches" : {
            "text" : {
              "select" : "account:field-i-am-willing-to:0",
              "php" : { "code" : "if ($value == \\u0027peer_review\\u0027 || $value == \\u0027chair\\u0027 || $value == \\u0027blind_review\\u0027 || $value == \\u0027discuss\\u0027) {\\r\\nreturn \\u0027success\\u0027;\\r\\n}" }
            },
            "match" : "success"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } }
      ]
    }
  }');
  $items['rules_add_volunteer_role_new_users'] = entity_import('rules_config', '{ "rules_add_volunteer_role_new_users" : {
      "LABEL" : "add volunteer role new users",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "text_matches" : {
            "text" : {
              "select" : "account:field-i-am-willing-to:0",
              "php" : { "code" : "if ($value == \\u0027peer_review\\u0027 || $value == \\u0027chair\\u0027 || $value == \\u0027blind_review\\u0027 || $value=\\u0027discuss\\u0027) {\\r\\nreturn \\u0027success\\u0027;\\r\\n}" }
            },
            "match" : "success"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } }
      ]
    }
  }');
  return $items;
}
