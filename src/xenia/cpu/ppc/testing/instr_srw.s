test_srw_1:
  #_ REGISTER_IN r4 1
  #_ REGISTER_IN r5 0
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 1
  #_ REGISTER_OUT r4 1
  #_ REGISTER_OUT r5 0

test_srw_1_constant:
  li r4, 1
  li r5, 0
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 1
  #_ REGISTER_OUT r4 1
  #_ REGISTER_OUT r5 0

test_srw_2:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 0
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x00000000FFFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 0

test_srw_2_constant:
  li r4, -1
  li r5, 0
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x00000000FFFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 0

test_srw_3:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 1
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x000000007FFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 1

test_srw_3_constant:
  li r4, -1
  li r5, 1
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x000000007FFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 1

test_srw_4:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 63
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 63

test_srw_4_constant:
  li r4, -1
  li r5, 63
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 63

test_srw_5:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 64
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x00000000FFFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 64

test_srw_5_constant:
  li r4, -1
  li r5, 64
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x00000000FFFFFFFF
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 64

test_srw_6:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 100
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 100

test_srw_6_constant:
  li r4, -1
  li r5, 100
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 100

test_srw_7:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 30
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x0000000000000003
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 30

test_srw_7_constant:
  li r4, -1
  li r5, 30
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x0000000000000003
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 30

test_srw_8:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 31
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x0000000000000001
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 31

test_srw_8_constant:
  li r4, -1
  li r5, 31
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x0000000000000001
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 31

test_srw_9:
  #_ REGISTER_IN r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_IN r5 32
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 32

test_srw_9_constant:
  li r4, -1
  li r5, 32
  srw r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT r4 0xFFFFFFFFFFFFFFFF
  #_ REGISTER_OUT r5 32
