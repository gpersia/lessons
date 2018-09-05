import os
import time
import mmap

ptr = mmap.mmap(-1, mmap.PAGESIZE, mmap.MAP_SHARED, mmap.PROT_WRITE)

pid = os.fork()

if pid == 0: //hijo
    time.sleep(1)
    ptr[0]='5'
else: //padre
    print 'leido de memoria: ' + ptr[0]
    time.sleep(2)
    print 'leido de memoria: ' + ptr[0]
