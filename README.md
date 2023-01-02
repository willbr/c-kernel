# Call a C function from Python

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


# C repl
Actor model

* repl
* tcp repl
* live load DLL
* live compile c
* live compile my own language
* list functions
* call functions

```
Root
|
|-Process
| |-Thread
| |-Thread
|
|-Process
  |-Thread
  |-Thread

```
