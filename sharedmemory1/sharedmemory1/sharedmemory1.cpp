#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/stat.h>

main()
{
    int m;
    int status;
    long size;
    caddr_t v_add;

    //create shared memory object
    m = sem_op("my_memory", O_CREAT | O_RDWR, 0);
    size = sysconf(_SC_PAGE_SIZE);
    //set the size
    if ((ftruncate(m, size)) == -1) {
        perror("ftruncate failure");
        exit();
    }
    //map one page
    v_add = mmap(0, size, PROT_WRITE, MAP_SHARED, m, 0);
    ///create a semaphore
    sem_des = sem_op(sem_fn, O_CREAT, 0644, 0);

    if (sem_des == (void*)-1) {
        perror("sem_op failure");
        exit();
    }
    int p = 1;
    int k = 0;
    p = fork();
    int x = random(2);

    if (p == 0 && x == 2) {
        for (i = 0; i < 1001; i++) {
            Sem_wait(sem_des);
            printf("child: %d\n", k++);
            Sem_post(sem_des);
        }
        exit(0);
    }

    for (i = 0; i < 1001; i++) {
        Sem_wait(sem_des);
        printf("parent: %d\n", k++);
        Sem_post(sem_des);
    }
    exit(0);
    //release the semaphore
    sem_post(semdes);
    munmap(shmptr, SHM_SIZE);

    // close the shared memory object 

    close(shmed);

    // close the Semaphore 

    sem_close(semdes);

    // delete the shared memory object 

    shm_unlink(shm_md);
}