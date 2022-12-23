Call a C function from Python

```c
#include <stdio.h>

__declspec(dllexport)
void
say_hello(void) {
    puts("hello");
}
```

```powershell
tcc -shared lib-hello.c
```

```python
from ctypes import *

dll = WinDLL('./lib-hello.dll')
dll.say_hello()
```

