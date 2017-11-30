#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "threads/interrupt.h"
#include "threads/thread.h"
#include "userprog/process.h"

void syscall_init (void);
void syscall_exit(struct intr_frame *f, int status);
void syscall_exec (struct intr_frame *f, const char *cmd_line);
void syscall_wait (struct intr_frame *f, pid_t pid);
void syscall_create (struct intr_frame *f, const char* file, unsigned initial_size);
void syscall_remove(struct intr_frame *f, const char* file) ;
void syscall_open (struct intr_frame *f, const char* file_name);
void syscall_filesize (struct intr_frame *f, int fd);
void syscall_read (struct intr_frame *f, int fd, void* buffer, unsigned size);
void syscall_write(struct intr_frame *f, int fd, void* buffer, unsigned size);
void syscall_close (struct intr_frame *f UNUSED, int fd);
void syscall_seek(struct intr_frame *f UNUSED, int fd, unsigned position);
void syscall_tell(struct intr_frame *f, int fd);
void syscall_mmap(struct intr_frame *f, int fd, void* addr);
void syscall_munmap(struct intr_frame *f, int mapping);

bool validate_memory (void* ptr);

#endif /* userprog/syscall.h */
