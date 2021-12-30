int readers = 0;
Semaphore mutex = 1, write = 1;

// 读者进程
void reader() {
    wait(mutex);
    readers++;
    if (readers == 1) {
        wait(write);
    }
    signal(mutex);

    /*
    Doing Reading Stuff
    */

    wait(mutex);
    readers--;
    if (readers == 0) {
        signal(write);
    }
    signal(mutex);
}

// 写者进程
void writer() {
    wait(write);
    /*
    Doing Writing Stuff
    */
    signal(write);
}


int readers = 0;
Semaphore mutex = 1, waiting_rw = 1, waiting = 1;

// 读者进程
void reader() {
    wait(waiting);
    wait(mutex);
    if (readers == 0) {
        wait(waiting_rw);
    }
    readers++;
    signal(mutex);
    signal(waiting);

    /*
    Doing Reading Stuff
    */

    wait(mutex);
    readers--;
    if (readers == 0) {
        signal(waiting_rw);
    }
    signal(mutex);
}

// 写者进程
void writer() {
    wait(waiting);
    wait(waiting_rw);
    /*
    Doing Writing Stuff
    */
    signal(waiting_rw);
    signal(waiting);
}


