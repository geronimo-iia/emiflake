{
  'targets': [
    {
      'target_name': 'emiflake',
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      'sources': [
		'src/flake.cc',
		'src/module.cc',
		'src/EmiFlake.cc',
      ]
    }
  ]
}
