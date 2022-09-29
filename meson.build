project('winbug', 'c')

winbug_test = executable('winbug', 'winbug.c')
test('hang', winbug_test, args : ['hang'])
test('don\'t hang', winbug_test)
