import os
import time
import mmap

ptr = mmap.mmap(-1, mmap.PAGESIZE, mmap.MAP_SHARED, mmap.PROT_WRITE)

pid = os.fork()

if pid == 0: //hijo
    ptr[0]='5'
else: //padre
    time.sleep(1)
    print 'leido de memoria: ' + ptr[0]
