import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/admin/bumperbot_ws/install/bumperbot_py_examples'
