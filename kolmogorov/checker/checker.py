import ast
import io
import signal
import sys
from contextlib import redirect_stdout

sys.setrecursionlimit(10000)

def clean_code(c):
    m = ast.parse(c)

    class RemoveImportTransformer(ast.NodeTransformer):
        def visit_Import(self, node):
            return None

    RemoveImportTransformer().visit(m)
    m = ast.fix_missing_locations(m)
    codeobj = compile(m, '<string>', 'exec')
    return codeobj

l = int(input())
s = input()
input()
n = int(input())
c = "\n".join([input() for i in range(n)])

"""

Removed functions:
    __import__, breakpoint, compile, eval, exec, input, memoryview, open

https://docs.python.org/3/library/functions.html

"""
exec_builtins = {
        'abs': abs, 'all': all, 'any': any, 'ascii': ascii, 'bin': bin, 'bool': bool, 'bytearray': bytearray,
        'bytes': bytes, 'callable': callable, 'chr': chr, 'classmethod': classmethod, 'complex': complex,
        'delattr': delattr, 'dict': dict, 'dir': dir, 'divmod': divmod, 'enumerate': enumerate, 'filter': filter,
        'float': float, 'format': format, 'frozenset': frozenset, 'getattr': getattr, 'globals': globals,
        'hasattr': hasattr, 'hash': hash, 'help': help, 'hex': hex, 'id': id, 'int': int, 'isinstance': isinstance,
        'issubclass': issubclass, 'iter': iter, 'len': len, 'list': list, 'locals': locals, 'map': map, 'max': max,
        'min': min, 'next': next, 'object': object, 'oct': oct, 'ord': ord, 'pow': pow, 'print': print,
        'property': property, 'range': range, 'repr': repr, 'reversed': reversed, 'round': round, 'set': set,
        'setattr': setattr, 'slice': slice, 'sorted': sorted, 'staticmethod': staticmethod, 'str': str, 'sum': sum,
        'super': super, 'tuple': tuple, 'type': type, 'vars': vars, 'zip': zip,
}


def alarm_handler(signum, frame):
    sys.exit(1)
signal.signal(signal.SIGALRM, alarm_handler)

flag = False
err = False
with io.StringIO() as buf, redirect_stdout(buf):
    try:
        cobj = clean_code(c)

        signal.alarm(3)
        exec(cobj, {
            '__builtins__': exec_builtins
        }, {})
        flag = buf.getvalue()[:-1] == s
    except:
        err = True
        flag = False

if not flag:
    sys.exit(1)
print(10*max(0, 1 - len(c)/len("print(\""+s+"\")")))