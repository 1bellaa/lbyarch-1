# LBYARCH MP2 - GROUP 1
Created by: Pablo III Lucas & Rachel Lauren Manlapig

## Comparative Execution Time

| Vector Size | C Kernel Average Time | ASM Kernel Average Time | C Dot Product | ASM Dot Product |
| --- | ----------- | ----------| ----- | ----- |
|2<sup>20</sup> | 0.003800s | 0.000750s | 2,615,536,384.00 | 2,615,536,384.00 |
|2<sup>24</sup> | 0.060850s | 0.012650s | 40,691,335,168.00 | 40,691,335,168.00 |
|2<sup>28</sup> | 0.965050s | 0.202750s | 198,972,129,280.00 | 198,972,129,280.00 |
|2<sup>30</sup> | 3.878650s | 0.812650s | 2,474,877,906,944.00 | 2,474,877,906,944.00 |

## Short Analysis
Both the C and ASM kernels exhibit increasing execution times as the vector size grows, indicating a directly proportional relationship. However, the ASM kernel consistently outperforms the C kernel. For smaller vectors, the ASM kernel is approximately five times faster than the C kernel. Even with larger vectors, the ASM kernel maintains its advantage, being about 4.8 times faster than the C kernel. This suggests that the ASM kernel's performance scales more efficiently as the vector size increases.

The ASM kernel's performance can be attributed to its direct manipulation of hardware registers and instructions, which eliminates the overhead associated with the abstractions in C. For large vector sizes, efficient memory usage and reduced cache misses likely contribute to the ASM kernel's superior performance.

## Output Screenshots
![alt text](<vectors raise to 20 to 28.png>)
![alt text](<vector raise to 30.png>)
