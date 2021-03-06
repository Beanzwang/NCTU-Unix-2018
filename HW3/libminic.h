#ifdef __cplusplus
extern "C" {
#endif
#define pause _pause

#define _NSIG 64
#define _NSIG_BPW 64
#define _NSIG_WORDS (_NSIG / _NSIG_BPW)

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6
#define SIGIOT 6
#define SIGBUS 7
#define SIGFPE 8
#define SIGKILL 9
#define SIGUSR1 10
#define SIGSEGV 11
#define SIGUSR2 12
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGSTKFLT 16
#define SIGCHLD 17
#define SIGCONT 18
#define SIGSTOP 19
#define SIGTSTP 20
#define SIGTTIN 21
#define SIGTTOU 22
#define SIGURG 23
#define SIGXCPU 24
#define SIGXFSZ 25
#define SIGVTALRM 26
#define SIGPROF 27
#define SIGWINCH 28
#define SIGIO 29
#define SIGPOLL SIGIO
/*
#define SIGLOST     29
*/
#define SIGPWR 30
#define SIGSYS 31
#define SIGUNUSED 31

/* These should not be considered constants from userland.  */
#define SIGRTMIN 32
#ifndef SIGRTMAX
#define SIGRTMAX _NSIG
#endif

#define SA_NOCLDSTOP 0x00000001
#define SA_NOCLDWAIT 0x00000002
#define SA_SIGINFO 0x00000004
#define SA_ONSTACK 0x08000000
#define SA_RESTART 0x10000000
#define SA_NODEFER 0x40000000
#define SA_RESETHAND 0x80000000

#define SA_NOMASK SA_NODEFER
#define SA_ONESHOT SA_RESETHAND

#define SIG_BLOCK 0
#define SIG_UNBLOCK 1
#define SIG_SETMASK 2
#define siginfo_t void

typedef struct
{
	unsigned long sig[_NSIG_WORDS];

} sigset_t;

typedef struct jmp_buf_s
{
	long long reg[8];
	sigset_t mask;
} jmp_buf[1];



struct sigaction
{
	void (*sa_handler)(int);
	void (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_restorer)(void);
};

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
long sigaction(int how, const struct sigaction *nact, struct sigaction *oact);
int sigreturn(); // resumes execution at the point where it was interrupted by the signal.
int pause(void);
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);
unsigned int alarm(unsigned int seconds);
void exit(int code);
int write(int fd, char *ptr, int sz);
unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif
