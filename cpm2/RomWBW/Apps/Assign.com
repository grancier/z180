�s�	1�	�( ͯ �, :����͸�{�	�  �* ��"�!@ ~�W�O#~���O#~�)�T##~#fo##^#V#�S�^#V�S�*��+~#��O ��*��"�:���� *��~�� #~�� !�6���"�*��[���R"�*���"���!� �����/�B�A2�#~�:�J#���=(j:�K#��v�$�,�$�� �:�J#:��A2��#�
ڂ�҂2�~�:�J#�
ڂ2� ��(�,(�J���D��~��#���ý#~�?�Q�L��J͸�	�3:���	�3	
�3͸
�3͵A
�3���:�� "��C ͸�	�3�y�f>:������ H. �}��E ͸�	�3�y�͐��s>:����*� ��K����s�	*�:� s#� �!� >��(Y####�*�+s{��O !��[����S�!� ���"�*�+F #~��   ~��! �������x���##s#r#�͵�	�3*��[���R�|��3�W���O:��y GH�z�@(.E ���x("� (�(���(
� ( *�{��?^#V�>�?�K�q#p#s#r#������^#V#�|�(������q#p#���{�	! ��[��K���Ñ��[��8�[���R8�S����!�>��ʌ���J��ʇ>�?���>�?�~��(� #��+####����:�������:����!�:��?>�w�#w#w#w:��!�4��:����:����*�|��n!�:��?"�!�:��?"�*�� ��*��[� ��!��[� ��:��:��!�4��:�� s �!	�~#fo���+���(##��sy2���C ���:�� :��(��s�y����:����!��?"�q#:�w:��!�4��:�G H�z�@(p	�A(1t	�B(*z	�C(#}	�D(�s:�GE ���xl	(h	�s!��+�s:���s:����!��?"�:�w#:�w:��!�4�� x���y�������O!��?~��y��͸�	�3��!��?��A�>:�>=�~�����f>:��#~�s�� %��� ��_:��{ "O��z��!	�?~#V_�3��{�s����G�H�z��@(!�Ap	(.�Bt	('�Cz	( �D}	(�	�E ���x�l	(h	 �3x�s������Y�������sO�z�08��:���x��G H�z��s�@(��:���x�����_� �����>.�����(�������[z�{�����x�@y�@��W�j_z�jW��Ɛ'�@'��& o�|������͈�����0��ͥ�ͥ��ͥ�ͥ �>/<	8��B�� ��͸�>�>
���~��� �#���� �8�=��_��.��:��;��<��>ɯ�� ~�A8�[0#x�(�~�� ~�08�:0y�؁��O~�0��O#�y������#��~#�*��?�o�$��A
\�WR0M�͸I�3��A�`;c3~.�)$�E���͸��3��@͵�3���                                        ����������������������������������������������������������������9	<	?	D	H	N	T	W	]	c	7	7	7	7	7	7	? MD FD RAMF IDE ATAPI PPIDE SD PRPSD PPPSD HDSK RAM ROM IDE PPIDE SD DSD UNK                                                                         ASSIGN v1.0c for RomWBW CP/M 2.2, 21-Apr-2016  (HBIOS Mode)  (UBIOS Mode) Copyright 2016, Wayne Warthen, GNU GPL v3 Usage: ASSIGN D:[=[{D:|<device>[<unitnum>]:[<slicenum>]}]][,...]
  ex. ASSIGN           (display all active assignments)
      ASSIGN /?        (display version and usage)
      ASSIGN /L        (display all possible devices)
      ASSIGN C:=D:     (swaps C: and D:)
      ASSIGN C:=FD0:   (assign C: to floppy unit 0)
      ASSIGN C:=IDE0:1 (assign C: to IDE unit0, slice 1)
      ASSIGN C:=       (unassign C:) Parameter error (ASSIGN /? for usage) Unexpected CBIOS (signature missing) Unexpected CBIOS version Invalid drive letter ( :) Invalid drive swap request Invalid device name (ASSIGN /L for device list) Specified device does not support slices Unit or slice number invalid Disk buffer exceeded in CBIOS, aborted Only hard drive devices can be reassigned Multiple drive letters reference one filesystem, aborting! Drive A: is unassigned, aborting! DOS error, return code=0x  Disk Buffer Bytes Free 