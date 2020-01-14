# Least Common Multiple Shell
To develop this simple demo, to begin with, I used Gradle 'init' task so as to obtain an application skeleton.

## Least Common Multiple and Greatest Common Divisor
I would like to remind you that the two algorithms examined have applications that should be defined as universal.

## Disassembly example
Below is a piece of the object file disassembled with the sections: .text, .bss and .rodata

```
Disassembly of section .text:

0000000000000000 <_ZN12paolomococci5Hello8getHelloB5cxx11Ev>:
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 28          	sub    rsp,0x28
   9:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   d:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
  11:	48 8d 45 ef          	lea    rax,[rbp-0x11]
  15:	48 89 c7             	mov    rdi,rax
  18:	e8 00 00 00 00       	call   1d <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x1d>
  1d:	48 8d 55 ef          	lea    rdx,[rbp-0x11]
  21:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  25:	be 00 00 00 00       	mov    esi,0x0
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x32>
  32:	48 8d 45 ef          	lea    rax,[rbp-0x11]
  36:	48 89 c7             	mov    rdi,rax
  39:	e8 00 00 00 00       	call   3e <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x3e>
  3e:	eb 1a                	jmp    5a <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x5a>
  40:	48 89 c3             	mov    rbx,rax
  43:	48 8d 45 ef          	lea    rax,[rbp-0x11]
  47:	48 89 c7             	mov    rdi,rax
  4a:	e8 00 00 00 00       	call   4f <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x4f>
  4f:	48 89 d8             	mov    rax,rbx
  52:	48 89 c7             	mov    rdi,rax
  55:	e8 00 00 00 00       	call   5a <_ZN12paolomococci5Hello8getHelloB5cxx11Ev+0x5a>
  5a:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  5e:	48 83 c4 28          	add    rsp,0x28
  62:	5b                   	pop    rbx
  63:	5d                   	pop    rbp
  64:	c3                   	ret    

0000000000000065 <main>:
  65:	55                   	push   rbp
  66:	48 89 e5             	mov    rbp,rsp
  69:	53                   	push   rbx
  6a:	48 83 ec 38          	sub    rsp,0x38
  6e:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  72:	48 8d 55 cf          	lea    rdx,[rbp-0x31]
  76:	48 89 d6             	mov    rsi,rdx
  79:	48 89 c7             	mov    rdi,rax
  7c:	e8 00 00 00 00       	call   81 <main+0x1c>
  81:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  85:	48 89 c6             	mov    rsi,rax
  88:	bf 00 00 00 00       	mov    edi,0x0
  8d:	e8 00 00 00 00       	call   92 <main+0x2d>
  92:	be 00 00 00 00       	mov    esi,0x0
  97:	48 89 c7             	mov    rdi,rax
  9a:	e8 00 00 00 00       	call   9f <main+0x3a>
  9f:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  a3:	48 89 c7             	mov    rdi,rax
  a6:	e8 00 00 00 00       	call   ab <main+0x46>
  ab:	bf 00 00 00 00       	mov    edi,0x0
  b0:	e8 00 00 00 00       	call   b5 <main+0x50>
  b5:	48 89 c3             	mov    rbx,rax
  b8:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  bc:	48 89 c7             	mov    rdi,rax
  bf:	e8 00 00 00 00       	call   c4 <main+0x5f>
  c4:	48 89 d8             	mov    rax,rbx
  c7:	48 89 c7             	mov    rdi,rax
  ca:	e8 00 00 00 00       	call   cf <_Z41__static_initialization_and_destruction_0ii>

00000000000000cf <_Z41__static_initialization_and_destruction_0ii>:
  cf:	55                   	push   rbp
  d0:	48 89 e5             	mov    rbp,rsp
  d3:	48 83 ec 10          	sub    rsp,0x10
  d7:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  da:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
  dd:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1
  e1:	75 27                	jne    10a <_Z41__static_initialization_and_destruction_0ii+0x3b>
  e3:	81 7d f8 ff ff 00 00 	cmp    DWORD PTR [rbp-0x8],0xffff
  ea:	75 1e                	jne    10a <_Z41__static_initialization_and_destruction_0ii+0x3b>
  ec:	bf 00 00 00 00       	mov    edi,0x0
  f1:	e8 00 00 00 00       	call   f6 <_Z41__static_initialization_and_destruction_0ii+0x27>
  f6:	ba 00 00 00 00       	mov    edx,0x0
  fb:	be 00 00 00 00       	mov    esi,0x0
 100:	bf 00 00 00 00       	mov    edi,0x0
 105:	e8 00 00 00 00       	call   10a <_Z41__static_initialization_and_destruction_0ii+0x3b>
 10a:	90                   	nop
 10b:	c9                   	leave  
 10c:	c3                   	ret    

000000000000010d <_GLOBAL__sub_I__ZN12paolomococci5Hello8getHelloB5cxx11Ev>:
 10d:	55                   	push   rbp
 10e:	48 89 e5             	mov    rbp,rsp
 111:	be ff ff 00 00       	mov    esi,0xffff
 116:	bf 01 00 00 00       	mov    edi,0x1
 11b:	e8 af ff ff ff       	call   cf <_Z41__static_initialization_and_destruction_0ii>
 120:	5d                   	pop    rbp
 121:	c3                   	ret    

Disassembly of section .bss:

0000000000000000 <_ZStL8__ioinit>:
	...

Disassembly of section .rodata:

0000000000000000 <_ZStL19piecewise_construct>:
   0:	00 48 69             	add    BYTE PTR [rax+0x69],cl
   3:	21 00                	and    DWORD PTR [rax],eax
```

Note that registers begin with the letter r, which highlights a 64-bit system, and the mangling of the names of the functions managed by the C++ language, so as to enrich the names by adding the namespace.
