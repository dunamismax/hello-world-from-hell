??=include<stdio.h>
??=include<stdlib.h>
??=include<string.h>
??=include<time.h>
??=include<unistd.h>
??=include<stdarg.h>
??=include<setjmp.h>
??=include<signal.h>
??=include<stdint.h>
??=include<stdatomic.h>
??=include<stdalign.h>
??=include<stdnoreturn.h>
??=include<complex.h>
??=include<math.h>
??=include<stdbool.h>
??=include<pthread.h>
??=ifdef X86_64
??=ifdef __has_include
??=if __has_include(<immintrin.h>)
??=include<immintrin.h>
??=define SIMD_AVAILABLE 1
??=else
??=define SIMD_AVAILABLE 0
??=endif
??=else
??=define SIMD_AVAILABLE 0
??=endif
??=elif defined(ARM64)
??=ifdef __has_include
??=if __has_include(<arm_neon.h>)
??=include<arm_neon.h>
??=define SIMD_AVAILABLE 1
??=else
??=define SIMD_AVAILABLE 0
??=endif
??=else
??=define SIMD_AVAILABLE 0
??=endif
??=else
??=define SIMD_AVAILABLE 0
??=endif
??=define CHAOS(x) x
??=define CURSE(a,b) (((a)??!(b))^((a)&(b)))
??=define MORPH(x) ((x)<<1)|((x)>>7)
??=define TWIST(a,b,c) ((CURSE(MORPH(a),(b)))^(c))
??=define VOID 0x00
??=define DARK 0xFF
??=define SPELL(s) s,sizeof(s)-1
??=define RITUAL(x) do??<x??>while(VOID)
??=define SUMMON(...) __VA_ARGS__
??=define BIND(x) static volatile x
??=define PHANTOM(x) ((void*)(x))
??=define GHOST(x) ((char*)(x))
??=define SHADOW(x,y) ((x)(y))
??=define ECHO(x) x,x
??=define MIRROR(a,b) b,a
??=define VORTEX(x) (x)=(x)^(x)
??=define ARCANE_SHIFT(n) (((n)<<4)|((n)>>4))&0xFF
??=define HEXIFY(c) ARCANE_SHIFT(c^0x42)
??=define UNHEX(c) ((ARCANE_SHIFT(c))^0x42)
??=define CURSED_LOOP(init,cond,inc,body) for(init;cond;inc)body
??=define DUFFS_REVENGE(n,action) do??<int cnt=(n);switch(cnt%8)??<case 0:do??<action;case 7:action;case 6:action;case 5:action;case 4:action;case 3:action;case 2:action;case 1:action;??>while((cnt-=8)>0);??>??>while(0)
??=define FIBONACCI_CHAOS(a,b) (a+b),(b),(a)
??=define QUANTUM_WRITE(c) SHADOW(putchar,UNHEX(c))
??=define DIMENSION_SHIFT jmp_buf
??=define PORTAL setjmp
??=define WORMHOLE longjmp
??=define SOUL volatile sig_atomic_t
??=define BANISH(x) ((void)(x))
??=define MANIFEST(type,name) type name=(type)(uintptr_t)&name
??=define RECURSIVE_NIGHTMARE(f,x) f(x)
??=define OBFUSCATE(s) s^0xDEADBEEF
??=define DEOBFUSCATE(s) s^0xDEADBEEF
??=define EVIL_COMMA ,
??=define CURSED_SEMICOLON ;
??=define HELLISH_DOT .
??=define DEMONIC_COLON :
??=define INFERNAL_PERMIT_MATRIX(X) \
    X(FORM_WORLD_O, 7, 'o', "Form O-71: orbital vowel requisition") \
    X(FORM_L3, 9, 'l', "Form L-93: terminal lateral approval") \
    X(FORM_H, 0, 'H', "Form H-13: greeting ignition waiver") \
    X(FORM_SPACE, 5, ' ', "Form SPC-66: licensed ceremonial void") \
    X(FORM_E, 1, 'e', "Form E-22: vowel manifestation permit") \
    X(FORM_BANG, 11, '!', "Form EX-99: punctuation detonation order") \
    X(FORM_L1, 2, 'l', "Form L-41: first lateral compliance stamp") \
    X(FORM_W, 6, 'W', "Form W-72: consonant escalation request") \
    X(FORM_D, 10, 'd', "Form D-88: final consonant discharge") \
    X(FORM_R, 8, 'r', "Form R-77: rotational phoneme variance") \
    X(FORM_HELLO_O, 4, 'o', "Form O-57: circular vowel notarization") \
    X(FORM_L2, 3, 'l', "Form L-58: second lateral affidavit") \
    X(FORM_NEWLINE, 12, '\n', "Form LF-13: newline release to mortal realm")
??=define BOARD_MEETING_AGENDA(X) \
    X(QUORUM, "[QUORUM ACKNOWLEDGED BY THE DAMNED]\n") \
    X(GREETING, "Hello") \
    X(VOIDSPACE, " ") \
    X(WORLD, "World") \
    X(FINALE, "!\n") \
    X(MOTION, "[MOTION CARRIES. THE PIT APPLAUDS.]\n")
??=define APOCALYPSE_SCRIPT(X) \
    X("LEGAL REVIEW OF THE ABYSS", 9) \
    X("TEMPORAL INCIDENT REPORT", 8) \
    X("BOARD MEETING FROM HELL", 10) \
    X("SETJMP INCIDENT REMEDIATION", 6) \
    X("QUANTUM POSTMORTEM", 7)

/*
⢰⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼
⠀⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠴⠶⠖⠒⠛⣿⣽⡟⠛⠓⠒⠶⠶⢤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠴⣯⠏
⠀⠀⢿⣯⣿⠷⣶⣤⡴⣶⣶⣤⠤⠤⣤⣄⡀⠀⣀⡤⠶⠛⠉⠀⠀⠀⠀⠀⠀⠴⠿⣼⠿⠦⠀⠀⠀⠀⠀⠀⠉⠛⠲⢦⣄⣀⣤⣴⠒⣻⣿⣿⢻⣿⣿⣿⠋⣩⣴⠋⠀
⠀⠀⠀⠙⠿⣦⣼⣟⢷⣷⢹⣿⣌⣿⡟⢺⣿⠛⠻⣄⠀⠀⠀⠀⢀⣠⣤⠤⠖⠒⠒⠛⠒⠒⠒⠦⠤⣤⣀⠀⠀⢀⣤⠖⠛⢿⣇⠐⡾⣷⣿⡟⢚⣿⣷⣿⠶⠋⠁⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠛⠛⠻⠾⢿⣾⣮⣗⣸⣿⣆⠄⠀⠙⣦⡖⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢉⣷⡟⠀⡀⢨⣽⣿⣽⣶⢿⡿⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠛⠉⠙⠻⢿⣷⣶⡂⣸⡟⠓⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠛⣧⣄⣿⣾⣿⡋⠉⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⠀⠀⠀⣠⠾⣿⣿⣿⣿⡁⠀⠈⢳⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠋⠀⠀⣿⣿⣿⣫⣶⠟⢦⡀⠀⠀⣀⠹⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⡼⢿⡷⣾⠀⢀⡞⠁⠀⠹⡄⢻⣿⣿⡆⠀⠘⣿⣦⣤⣀⣀⠀⠀⣀⣀⣤⣶⣿⡯⠀⢀⣾⣿⡿⠋⢀⡞⠀⠀⠙⢆⣀⣿⣻⣯⣷⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⡾⠷⠛⢳⡞⣻⠋⠀⠀⠀⠀⢳⡀⢻⣿⣿⣦⣠⣿⡯⣷⡉⣽⠿⠿⠟⠉⣹⡯⣿⣷⣤⣾⣿⣿⠁⠀⣼⠃⠀⠀⠀⠈⠻⡍⠏⠁⠉⢷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠈⡱⠁⠀⠀⠀⠀⠀⠈⢷⠈⣿⣿⣿⠟⣿⣇⡝⣮⡈⠀⠀⠀⣴⡟⠀⢿⡟⢿⣻⣿⣇⠀⣰⠇⠀⠀⠀⠀⠀⠀⠙⡄⠀⠀⠀⢿⡀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠇⠀⠀⠀⡼⠃⠀⠀⠀⣀⣀⣠⣤⣼⠿⣿⢿⠃⣰⠋⠈⠁⢻⡙⢶⣴⠟⣹⠃⠀⠀⠱⡄⢹⣿⣟⠲⢿⠤⠤⣤⣤⣀⡀⠀⠀⠸⡆⠀⠀⠈⣧⠀⠀⠀
⠀⠀⠀⠀⢠⡏⠀⠀⠀⣰⣃⣤⠖⠋⣉⡡⢆⣠⠟⠁⣼⣿⡿⢸⣇⠶⠊⠀⢸⣷⠛⠉⢳⣿⠀⠀⠐⢶⠹⡌⣿⡿⣆⠈⠱⢦⡐⠦⣄⣉⣙⣶⣄⣹⡀⠀⠀⢸⡇⠀⠀
⠀⠀⠀⠀⣾⠀⠀⢰⣶⣿⣿⣿⡿⢿⣥⣶⣟⣁⣠⣞⣽⠟⡇⢸⣿⡀⣀⡴⠋⢹⡄⠀⣸⣉⣻⣦⣄⣸⣰⡇⣿⢹⣮⣷⣤⣤⣿⠿⠞⣛⣿⣿⣿⣿⡿⠂⠀⠀⢿⠀⠀
⠀⠀⠀⠀⡟⠀⠀⠀⢹⠋⠳⢿⣿⣷⡶⠦⢭⣽⣾⣿⡟⠰⢷⣘⣿⠁⠿⠋⠉⠙⣿⠉⡿⠉⠉⠉⠏⢩⣿⢠⣟⣐⣿⣿⢷⣾⣷⣒⣩⣿⠿⠟⠉⠀⢱⠀⠀⠀⢸⠀⠀
⠀⠀⠀⢠⡇⠀⠀⠀⢸⠀⠀⠀⠈⠙⠻⠿⢿⣿⣿⣿⡟⣠⣾⣳⣽⣷⣦⢠⠄⣖⢹⣿⠃⠃⠠⠂⣰⣿⣿⢿⣧⣄⣻⣿⣿⣛⠟⠛⠋⠀⠀⠀⠀⠀⢸⡄⠀⠀⢸⡇⠀
⠀⠀⠀⢸⡇⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⢀⣸⠿⠋⢻⣿⣿⣿⣿⡽⣽⣾⣿⣦⣬⠞⠏⠀⢤⣼⣿⣿⣿⢱⣿⣿⣿⣿⡆⠈⠙⠲⣤⡀⠀⠀⠀⠀⠀⢸⡇⠀⠀⢸⡇⠀
⠀⠀⠀⠀⡇⢰⣄⣤⣾⠀⠀⠀⢀⣠⠶⠋⠁⠀⢀⣾⣿⢿⣿⣾⣇⢹⡏⣻⣿⠞⠀⠀⠀⠰⣿⣏⣸⡇⣾⣿⣿⣿⣿⣿⠀⠀⠀⠀⠙⠳⢦⣀⠀⠀⢸⢳⣦⡞⢸⡇⠀
⠀⠀⠀⠀⣷⡼⣯⡽⢿⣆⣤⣞⣋⣀⣀⣀⣀⣀⣸⣿⣿⣧⠬⠹⣯⣬⣿⠉⠹⣄⠀⠀⠀⣰⠏⠉⣿⢤⣿⠟⠲⣾⣿⣻⣧⣤⣤⣤⡤⠤⠤⠽⠿⢦⡼⠛⣷⠛⢿⠀⠀
⠀⠀⠀⠀⢻⡄⠘⠃⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣷⣄⠀⢻⣿⠏⢦⠀⠈⠐⠀⠸⡁⠀⡟⠙⣿⠟⠀⣠⣾⣿⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠙⢀⡿⠀⠀
⠀⠀⠀⠀⠘⣇⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣷⣄⠿⣄⠈⢿⡆⠀⠀⠀⢴⡿⠀⣠⠟⣠⣾⣿⢿⡽⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⠀⣸⠇⠀⠀
⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⢿⣶⡈⢦⢸⡇⠀⢠⠀⢸⡇⠐⢁⣼⣿⢿⣯⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠁⠀⠀⢠⡏⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢻⡄⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⣿⣿⣳⠀⠀⡇⠀⣼⠀⢸⡇⠀⣜⣿⣹⠶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⢀⡿⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⡄⠀⠀⠀⠈⢣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣯⡃⢸⡇⠀⢹⠂⠈⡇⠀⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠀⠀⠀⢠⡞⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⠷⣼⠃⠀⠀⠀⠀⢷⡰⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⣠⠟⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣄⠀⠀⠀⠀⠙⢦⣀⠀⠀⠀⠀⠀⠀⠀⢿⣴⣿⣦⣀⣠⣀⣤⣿⣧⢾⠆⠀⠀⠀⠀⠀⠀⠀⣠⠶⠃⠀⠀⠀⢀⡼⠋⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⣆⣉⣷⢦⣀⠀⠀⠀⠀⢸⡜⠿⣷⣿⣿⠿⣽⡿⠛⡞⠀⠀⠀⠀⢀⣠⣴⢊⣁⠀⠀⠀⢀⣴⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠦⣄⣠⢿⣩⡷⡄⠈⠙⠓⠤⢤⣀⣙⣦⣈⣻⣦⣾⣁⣠⣞⣁⣀⠤⠴⠚⠋⣀⣿⣻⣧⡀⣀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠦⣟⡀⠀⠀⠀⠀⠀⠀⠀⠉⠉⢿⡿⠷⣿⢿⡯⠉⠉⠀⠀⠀⠀⠀⠉⠉⣿⡾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠶⣄⣀⡀⠀⠀⠀⠀⠀⠙⣶⡿⢸⠇⠀⠀⠀⠀⣀⣠⠴⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠒⠒⠲⢾⣟⡥⠿⠒⠒⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
 */

static _Atomic SOUL chaos_counter = 0x13;
static DIMENSION_SHIFT reality;
static const int prophecy??(??) = ??<13,37,42,69,101,108,111,87,72,0??>CURSED_SEMICOLON
static _Alignas(64) volatile char quantum_buffer??(4096??);
static _Complex double eldritch_frequency = 6.66 + 13.37I;
static atomic_flag reality_lock = ATOMIC_FLAG_INIT;

typedef struct ??<
    _Alignas(32) unsigned char data??(??);
??> CursedMessage;

typedef union ??<
    long long quantum;
    double reality;
    void* void_ptr;
    char bytes??(??)CURSED_SEMICOLON
??> CosmicHorror;

typedef struct ??<
    unsigned approved : 1;
    unsigned notarized : 1;
    unsigned caffeinated : 1;
    unsigned tier : 5;
    unsigned encoded_order : 8;
    char glyph;
    const char *memo;
??> InfernalPermit;

typedef struct ??<
    const char *text;
    unsigned omen;
??> AgendaLine;

typedef struct ??<
    const char *label;
    int dimension;
??> ApocalypseStage;

typedef void (*InfernalEmitter)(void);
typedef void (*AgendaEmitter)(void);

typedef enum ??<
    VOID_STATE = -1,
    MORTAL_REALM = 0,
    SHADOW_REALM = 1,
    CHAOS_DIMENSION = 2,
    QUANTUM_REALM = 3,
    SIMD_HELL = 4,
    PARALLEL_NIGHTMARE = 5,
    OBLIVION = 0x80000000
??> DimensionType;

static void chaos_handler(int sig) ??<
    atomic_fetch_xor(&chaos_counter, (sig * 0x41C64E6D + 0x3039) & 0x7FFFFFFF);
    signal(sig EVIL_COMMA chaos_handler);
??>

static inline void summon_darkness(void) ??<
    unsigned seed = (unsigned)time(NULL) ^ (unsigned)getpid() ^ (unsigned)atomic_load(&chaos_counter);
    srand(seed);
    signal(SIGINT EVIL_COMMA chaos_handler);
    signal(SIGTERM EVIL_COMMA chaos_handler);
    
    for (size_t i = 0; i < sizeof(quantum_buffer); i++) ??<
        quantum_buffer??(i??) = (char)(seed ^ i ^ 0xDEADBEEF);
    ??>  
??>

static void __attribute__((noinline)) eldritch_print(const char *str) ??<
    if (!str) return;
    for (const char *p = str; *p; ++p) ??<
        chaos_counter = ((chaos_counter & 0x3FFFFFFF) << 1) ^ *p;
        if (chaos_counter & 1) ??<
            putchar(*p ^ ((chaos_counter >> 3) & 0x1F));
            putchar(8);
            putchar(*p);
        ??> else ??<
            putchar(*p);
        ??>
    ??>
??>

static void unholy_recursive_print(int depth EVIL_COMMA char c) ??<
    if (depth <= 0 || depth > 50) ??<
        putchar(c);
        return;
    ??>
    chaos_counter++;
    if (chaos_counter % 3 == 0) ??<
        unholy_recursive_print(depth - 1 EVIL_COMMA c);
    ??> else if (chaos_counter % 3 == 1) ??<
        unholy_recursive_print(depth - 1, c);
    ??> else ??<
        int temp = depth;
        while (temp-- > 1) BANISH(0);
        unholy_recursive_print(0 EVIL_COMMA c);
    ??>
??>

static char* cursed_strdup(const char* s) ??<
    if (!s) return NULL;
    size_t len = 0;
    for (const char* p = s; *p; p++) len++;
    char* result = malloc(len + 1);
    if (!result) return NULL;
    for (size_t i = 0; i <= len; i++) ??<
        result??(i??) = s??(i??);
    ??>
    return result;
??>

static void nightmare_printf(const char* fmt EVIL_COMMA ...) ??<
    va_list args;
    va_start(args, fmt);
    char buffer??(1024??);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    eldritch_print(buffer);
??>

static int quantum_strlen(const char* s) ??<
    if (!s) return -1;
    int len = 0;
    switch (rand() % 3) ??<
        case 0:
            while (s??(len??)) len++;
            break;
        case 1: ??<
            const char* p = s;
            while (*p++) len++;
            break;
        ??>
        default: ??<
            int i = 0;
            while (i < 1000 && s??(i??)) i++;
            len = i;
        ??>
    ??>
    return len;
??>

static unsigned decode_permit_order(const InfernalPermit *permit) ??<
    return (unsigned)(permit->encoded_order ^ 0x5AU);
??>

#define DECLARE_PERMIT_EMITTER(name, ordinal, glyph_value, memo_text) \
    static void emit_##name(void) ??< \
        unsigned stamp = (unsigned)(((ordinal) * 17U) ^ (unsigned char)(glyph_value) ^ (unsigned)atomic_load(&chaos_counter)); \
        if ((glyph_value) != '\n' && (stamp & 0x3U) == 0x3U) ??< \
            char typo = ((glyph_value) == ' ') ? '_' : (char)((glyph_value) ^ 0x20); \
            putchar(typo); \
            putchar(8); \
        ??> \
        putchar((glyph_value)); \
        atomic_fetch_xor(&chaos_counter, (int)((stamp | 1U) & 0xFFU)); \
    ??>
#define DECLARE_PERMIT_ENTRY(name, ordinal, glyph_value, memo_text) \
    { .approved = 1U, .notarized = ((ordinal) & 1U), .caffeinated = (((ordinal) >> 1) & 1U), .tier = (((ordinal) * 7U) + 3U) & 0x1FU, .encoded_order = ((ordinal) ^ 0x5AU), .glyph = (glyph_value), .memo = (memo_text) },
#define DECLARE_PERMIT_EMITTER_ENTRY(name, ordinal, glyph_value, memo_text) [ordinal] = emit_##name,

INFERNAL_PERMIT_MATRIX(DECLARE_PERMIT_EMITTER)

static const InfernalPermit infernal_permits??(??) = ??<
    INFERNAL_PERMIT_MATRIX(DECLARE_PERMIT_ENTRY)
??>;

static InfernalEmitter bureaucracy_emitters??(13??) = ??<
    INFERNAL_PERMIT_MATRIX(DECLARE_PERMIT_EMITTER_ENTRY)
??>;

#define DECLARE_AGENDA_EMITTER(name, line_text) \
    static void emit_agenda_##name(void) ??< \
        for (const char *p = (line_text); *p; ++p) ??< \
            putchar(*p); \
            atomic_fetch_xor(&chaos_counter, (((int)*p << 1) | 1)); \
        ??> \
    ??>
#define DECLARE_AGENDA_ENTRY(name, line_text) { .text = (line_text), .omen = (unsigned)(sizeof(line_text) * 13U) },
#define DECLARE_AGENDA_EMITTER_ENTRY(name, line_text) emit_agenda_##name,
#define DECLARE_APOCALYPSE_STAGE(stage_label, stage_dimension) { .label = (stage_label), .dimension = (stage_dimension) },

BOARD_MEETING_AGENDA(DECLARE_AGENDA_EMITTER)

static const AgendaLine board_agenda??(??) = ??<
    BOARD_MEETING_AGENDA(DECLARE_AGENDA_ENTRY)
??>;

static AgendaEmitter board_emitters??(6??) = ??<
    BOARD_MEETING_AGENDA(DECLARE_AGENDA_EMITTER_ENTRY)
??>;

static const ApocalypseStage apocalypse_stages??(??) = ??<
    APOCALYPSE_SCRIPT(DECLARE_APOCALYPSE_STAGE)
??>;

static int compare_infernal_permits(const void *lhs, const void *rhs) ??<
    const InfernalPermit *left = (const InfernalPermit *)lhs;
    const InfernalPermit *right = (const InfernalPermit *)rhs;
    unsigned decoded_left = decode_permit_order(left);
    unsigned decoded_right = decode_permit_order(right);

    if (decoded_left < decoded_right) return -1;
    if (decoded_left > decoded_right) return 1;
    return strcmp(left->memo, right->memo);
??>

static void infernal_bureaucracy(void) ??<
    InfernalPermit paperwork??(sizeof(infernal_permits) / sizeof(infernal_permits??(0??))??);
    memcpy(paperwork, infernal_permits, sizeof(paperwork));
    qsort(paperwork,
          sizeof(paperwork) / sizeof(paperwork??(0??)),
          sizeof(paperwork??(0??)),
          compare_infernal_permits);

    for (size_t i = 0; i < sizeof(paperwork) / sizeof(paperwork??(0??)); i++) ??<
        atomic_fetch_add(&chaos_counter,
                         paperwork??(i??).tier + quantum_strlen(paperwork??(i??).memo));
        bureaucracy_emitters??(decode_permit_order(&paperwork??(i??))??)();
    ??>
??>

static void board_meeting_from_hell(void) ??<
    size_t agenda_items = sizeof(board_agenda) / sizeof(board_agenda??(0??));
    unsigned chair_approval = (unsigned)(atomic_load(&chaos_counter) & 0xFF);

    for (size_t i = 0; i < agenda_items; i++) ??<
        atomic_fetch_add(&chaos_counter, (int)(board_agenda??(i??).omen + chair_approval));
        board_emitters??(i??)();
        chair_approval = (chair_approval + board_agenda??(i??).omen + 0x13U) & 0xFFU;
    ??>
??>

static void dispatch_dimension(int dimension);
static void apocalypse_protocol(void);

static void dimensional_shift(void) ??<
    CosmicHorror horror;
    horror.quantum = 0x48656C6C6F20576FLL;
    for (int i = 0; i < 8; i++) ??<
        if (horror.bytes??(i??) != 0) ??<
            chaos_counter ^= horror.bytes??(i??);
            putchar(horror.bytes??(i??));
        ??>
    ??>
    horror.quantum = 0x726C64210A00LL;
    for (int i = 0; i < 8; i++) ??<
        if (horror.bytes??(i??) != 0) ??<
            putchar(horror.bytes??(i??));
        ??>
    ??>
??>

static void fibonacci_madness(void) ??<
    int a = 72, b = 101;
    int sequence??(13??);
    sequence??(0??) = a;
    sequence??(1??) = b;

    for (int i = 2; i < 13; i++) ??<
        sequence??(i??) = (sequence??(i-1??) + sequence??(i-2??)) % 256;
    ??>

    char msg??(??) = "Hello World!\n";
    for (int i = 0; msg??(i??); i++) ??<
        int idx = (i + chaos_counter) % 13;
        putchar(msg??(i??) ^ (sequence??(idx??) & 0x1F));
        putchar(8);
        putchar(msg??(i??));
    ??>
??>

static void __attribute__((constructor)) awakening(void) ??<
    chaos_counter = ((chaos_counter & 0x0FFFFFFF) << 2) | ((chaos_counter & 0xFC) >> 6);
??>

static void __attribute__((destructor)) apocalypse(void) ??<
    chaos_counter = 0;
??>

static void duffs_device_horror(void) ??<
    static const char hellish_message??(??) = "Hello World!\n";
    DUFFS_REVENGE(quantum_strlen(hellish_message),
                  chaos_counter++;
                  { int safe_index = 13 - ((chaos_counter < 0 ? -chaos_counter : chaos_counter) % 14);
                  if (safe_index >= 0 && safe_index < 14) putchar(hellish_message??(safe_index??)); }
    );
??>

static void trigraph_nightmare(void) ??<
    static CursedMessage const abomination = ??<
        .data = ??<
            HEXIFY('H'), HEXIFY('e'), HEXIFY('l'), HEXIFY('l'), HEXIFY('o'),
            HEXIFY(' '), HEXIFY('W'), HEXIFY('o'), HEXIFY('r'), HEXIFY('l'),
            HEXIFY('d'), HEXIFY('!'), HEXIFY('\n'), HEXIFY('\0')
        ??>
    ??>;

    for (const unsigned char *p = abomination.data; *p; p++) ??<
        switch (chaos_counter % 4) ??<
            case 0: QUANTUM_WRITE(*p); break;
            case 1: QUANTUM_WRITE(*p); break;
            case 2: ??<
                volatile unsigned char temp = *p;
                QUANTUM_WRITE(temp);
                break;
            ??>
            default: ??<
                if (PORTAL(reality) == 0) ??<
                    QUANTUM_WRITE(*p);
                    chaos_counter++;
                    if (chaos_counter > 100) WORMHOLE(reality EVIL_COMMA 1);
                ??> else ??<
                    break;
                ??>
            ??>
        ??>
        chaos_counter = CURSE(chaos_counter, *p);
    ??>
??>

static void pointer_arithmetic_insanity(void) ??<
    char* message = cursed_strdup("Hello World!\n");
    if (!message) return;

    char* start = message;
    char* end = message + quantum_strlen(message);

    while (start < end && *start) ??<
        chaos_counter = TWIST(*start, chaos_counter, 0x55);
        if (chaos_counter & 1) ??<
            putchar((*start) ^ 0x00);
        ??> else ??<
            putchar(*start);
        ??>
        start = (char*)((uintptr_t)start + 1);
    ??>

    free(message);
??>

static void macro_expansion_hell(void) ??<
    CURSED_LOOP(int i = 0,
                i < 13,
                i++,
                SUMMON(putchar("Hello World!\n"??(i??))););
??>

static void signal_handler_chaos(void) ??<
    static volatile int signal_count = 0;

    if (signal_count++ > 0) return;

    pid_t pid = getpid();
    chaos_counter ^= pid;

    char* volatile msg = "Hello World!\n";
    while (*msg) ??<
        putchar(*msg++);
    ??>
??>

static void setjmp_longjmp_madness(void) ??<
    DIMENSION_SHIFT local_reality;
    static int iteration = 0;

    if (PORTAL(local_reality) == 0) ??<
        iteration++;
        if (iteration == 1) ??<
            nightmare_printf("Hello ");
            WORMHOLE(local_reality, 1);
        ??> else if (iteration == 2) ??<
            nightmare_printf("World!\n");
            WORMHOLE(local_reality, 2);
        ??>
    ??> else if (iteration == 1) ??<
        iteration++;
        WORMHOLE(local_reality, 0);
    ??>
??>

??=if SIMD_AVAILABLE
static void simd_hell_unleashed(void) ??<
??=ifdef X86_64
    alignas(32) char message??(32??) = "Hello World!\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    __m256i data = _mm256_load_si256((__m256i*)message);
    __m256i chaos = _mm256_set1_epi8((char)atomic_load(&chaos_counter));
    __m256i cursed = _mm256_xor_si256(data, chaos);
    
    alignas(32) char output??(32??);
    _mm256_store_si256((__m256i*)output, cursed);
    
    for (int i = 0; i < 14; i++) ??<
        putchar(output??(i??) ^ (char)atomic_fetch_add(&chaos_counter, 1));
        putchar(8);
        putchar(message??(i??));
    ??>
??=elif defined(ARM64)
    alignas(16) char message??(16??) = "Hello World!\n\0\0\0";
    uint8x16_t data = vld1q_u8((uint8_t*)message);
    uint8x16_t chaos = vdupq_n_u8((uint8_t)atomic_load(&chaos_counter));
    uint8x16_t cursed = veorq_u8(data, chaos);
    
    alignas(16) char output??(16??);
    vst1q_u8((uint8_t*)output, cursed);
    
    for (int i = 0; i < 14; i++) ??<
        putchar(output??(i??) ^ (char)atomic_fetch_add(&chaos_counter, 1));
        putchar(8);
        putchar(message??(i??));
    ??>
??=endif
??>
??=endif

static void* parallel_nightmare_thread(void* arg) ??<
    char* msg = (char*)arg;
    if (*msg) ??<
        while (atomic_flag_test_and_set(&reality_lock)) ??<
            usleep(1000);
        ??>
        putchar(*msg);
        atomic_flag_clear(&reality_lock);
    ??>
    
    return NULL;
??>

static void parallel_dimension_chaos(void) ??<
    char* hellish_msg = "Hello World!\n";
    pthread_t demons??(14??);
    int created_threads??(14??);
    int thread_count = 0;
    
    for (int i = 0; i < 13 && hellish_msg??(i??); i++) ??<
        if (pthread_create(&demons??(i??), NULL, parallel_nightmare_thread, &hellish_msg??(i??)) == 0) ??<
            created_threads??(i??) = 1;
            thread_count++;
        ??> else ??<
            created_threads??(i??) = 0;
            putchar(hellish_msg??(i??));
        ??>
    ??>
    
    for (int i = 0; i < 13; i++) ??<
        if (created_threads??(i??)) ??<
            pthread_join(demons??(i??), NULL);
        ??>
    ??>
??>

static void quantum_entanglement_horror(void) ??<
    _Complex double quantum_state = eldritch_frequency;
    char quantum_msg??(??) = "Hello World!\n";
    
    for (int i = 0; quantum_msg??(i??); i++) ??<
        quantum_state *= (1.0 + 0.1I);
        double real_part = creal(quantum_state);
        double imag_part = cimag(quantum_state);
        
        char entangled = quantum_msg??(i??) ^ ((int)real_part & 0xFF) ^ ((int)imag_part & 0xFF);
        putchar(entangled);
        putchar(8);
        putchar(quantum_msg??(i??));
        
        atomic_fetch_add(&chaos_counter, (int)(real_part * imag_part) & 0xFF);
    ??>
??>

static void temporal_loop_catastrophe(void) ??<
    static int temporal_depth = 0;
    char temporal_msg??(??) = "Hello World!\n";
    int temporal_len = quantum_strlen(temporal_msg);
    if (temporal_len < 0) return;
    
    if (temporal_depth > 10) ??<
        for (int i = 0; i < temporal_len; i++) putchar(temporal_msg??(i??));
        return;
    ??>
    
    temporal_depth++;
    
    switch (atomic_load(&chaos_counter) % 3) ??<
        case 0:
            for (int i = temporal_len - 2; i >= 0; i--) ??<
                putchar(temporal_msg??(i??));
            ??>
            break;
        case 1:
            if (temporal_depth < 8) ??<
                temporal_loop_catastrophe();
            ??> else ??<
                for (int i = 0; i < temporal_len; i++) putchar(temporal_msg??(i??));
            ??>
            break;
        default:
            for (int i = 0; i < temporal_len; i += 2) ??<
                putchar(temporal_msg??(i??));
            ??>
            for (int i = 1; i < temporal_len; i += 2) ??<
                putchar(temporal_msg??(i??));
            ??>
    ??>
    
    temporal_depth--;
??>

static void ultimate_chaos_fusion(void) ??<
    int chaos_level = atomic_load(&chaos_counter);
    if (chaos_level < 0) chaos_level = -chaos_level;
    chaos_level %= 14;

    switch (chaos_level) ??<
        case 0: dimensional_shift(); break;
        case 1: fibonacci_madness(); break;
        case 2: duffs_device_horror(); break;
        case 3: trigraph_nightmare(); break;
        case 4: pointer_arithmetic_insanity(); break;
        case 5: macro_expansion_hell(); break;
        case 6: setjmp_longjmp_madness(); break;
        case 7: quantum_entanglement_horror(); break;
        case 8: temporal_loop_catastrophe(); break;
        case 9: infernal_bureaucracy(); break;
        case 10: board_meeting_from_hell(); break;
??=if SIMD_AVAILABLE
        case 11: simd_hell_unleashed(); break;
??=else
        case 11: signal_handler_chaos(); break;
??=endif
        case 12: parallel_dimension_chaos(); break;
        case 13: apocalypse_protocol(); break;
        default: signal_handler_chaos(); break;
    ??>
??>

static void dispatch_dimension(int dimension) ??<
    switch (dimension) ??<
        case 0: dimensional_shift(); break;
        case 1: fibonacci_madness(); break;
        case 2: duffs_device_horror(); break;
        case 3: trigraph_nightmare(); break;
        case 4: pointer_arithmetic_insanity(); break;
        case 5: macro_expansion_hell(); break;
        case 6: setjmp_longjmp_madness(); break;
        case 7: quantum_entanglement_horror(); break;
        case 8: temporal_loop_catastrophe(); break;
        case 9: infernal_bureaucracy(); break;
        case 10: board_meeting_from_hell(); break;
        default: dimensional_shift(); break;
    ??>
??>

static void apocalypse_protocol(void) ??<
    size_t total_stages = sizeof(apocalypse_stages) / sizeof(apocalypse_stages??(0??));

    printf("=== APOCALYPSE PROTOCOL ENGAGED ===\n");
    for (size_t i = 0; i < total_stages; i++) ??<
        printf("--- PHASE %zu/%zu: %s ---\n", i + 1, total_stages, apocalypse_stages??(i??).label);
        atomic_fetch_add(&chaos_counter, (int)((i + 1) * 13));
        dispatch_dimension(apocalypse_stages??(i??).dimension);
        if (i + 1 < total_stages) putchar('\n');
    ??>
    printf("=== APOCALYPSE STATUS: GREETING DEPLOYED ===\n");
??>

static void print_cursed_help(void) ??<
    printf("CURSED HELLO WORLD FROM THE DEPTHS OF PROGRAMMING HELL\n");
    printf("Usage: ./cursed_spawn [OPTIONS]\n\n");
    printf("OPTIONS:\n");
    printf("  -h, --help           Show this unholy documentation\n");
    printf("  -d, --dimension N    Force specific hell dimension (0-10)\n");
    printf("  -c, --chaos N        Set initial chaos counter value\n");
    printf("  -r, --repeat N       Repeat the cursed ritual N times\n");
    printf("  -t, --threads        Enable parallel nightmare mode\n");
    printf("  -q, --quantum        Force quantum entanglement horror\n");
    printf("  -s, --simd           Force SIMD hell (if available)\n");
    printf("  -a, --apocalypse     Run the full compliance-collapse ceremony\n");
    printf("  --version            Show version and exit\n\n");
    printf("DIMENSIONS:\n");
    printf("  0: Dimensional shift         6: setjmp/longjmp madness\n");
    printf("  1: Fibonacci madness         7: Quantum entanglement horror\n");
    printf("  2: Duff's device horror      8: Temporal loop catastrophe\n");
    printf("  3: Trigraph nightmare        9: Infernal bureaucracy\n");
    printf("  4: Pointer arithmetic        10: Board meeting from hell\n");
    printf("  5: Macro expansion hell\n\n");
    printf("Default mode may now trigger paperwork, temporal failures, or total apocalypse.\n");
    printf("May your terminal survive the cursed output...\n");
??>

int main(int argc, char* argv[]) ??<
    summon_darkness();
    
    int forced_dimension = -1;
    int repeat_count = 1;
    bool force_parallel = false;
    bool force_quantum = false;
    bool force_simd = false;
    bool force_apocalypse = false;
    
    for (int i = 1; i < argc; i++) ??<
        if (strcmp(argv??(i??), "-h") == 0 || strcmp(argv??(i??), "--help") == 0) ??<
            print_cursed_help();
            return 0;
        ??> else if (strcmp(argv??(i??), "--version") == 0) ??<
            printf("Hello World From Hell v3.0.0 - Compliance Collapse Edition\n");
            printf("Compiled with %s\n", __VERSION__);
            printf("Architecture: %s\n", 
??=ifdef X86_64
                "x86_64"
??=elif defined(ARM64)
                "ARM64"
??=else
                "Unknown"
??=endif
            );
            printf("Crisis mode: paperwork, temporal recursion, and board-approved apocalypse\n");
            return 0;
        ??> else if (strcmp(argv??(i??), "-d") == 0 || strcmp(argv??(i??), "--dimension") == 0) ??<
            if (i + 1 < argc) ??<
                forced_dimension = atoi(argv??(++i??));
            ??>
        ??> else if (strcmp(argv??(i??), "-c") == 0 || strcmp(argv??(i??), "--chaos") == 0) ??<
            if (i + 1 < argc) ??<
                atomic_store(&chaos_counter, atoi(argv??(++i??)));
            ??>
        ??> else if (strcmp(argv??(i??), "-r") == 0 || strcmp(argv??(i??), "--repeat") == 0) ??<
            if (i + 1 < argc) ??<
                repeat_count = atoi(argv??(++i??));
                if (repeat_count < 1) repeat_count = 1;
                if (repeat_count > 666) repeat_count = 666;
            ??>
        ??> else if (strcmp(argv??(i??), "-t") == 0 || strcmp(argv??(i??), "--threads") == 0) ??<
            force_parallel = true;
        ??> else if (strcmp(argv??(i??), "-q") == 0 || strcmp(argv??(i??), "--quantum") == 0) ??<
            force_quantum = true;
        ??> else if (strcmp(argv??(i??), "-s") == 0 || strcmp(argv??(i??), "--simd") == 0) ??<
            force_simd = true;
        ??> else if (strcmp(argv??(i??), "-a") == 0 || strcmp(argv??(i??), "--apocalypse") == 0) ??<
            force_apocalypse = true;
        ??>
    ??>

    CosmicHorror reality_bender;
    reality_bender.quantum = (long long)&main;
    reality_bender.reality = 3.14159265359;

    MANIFEST(int*, cursed_ptr);
    BANISH(cursed_ptr);

    for (int ritual = 0; ritual < repeat_count; ritual++) ??<
        if (repeat_count > 1) ??<
            printf("=== RITUAL %d/%d ===\n", ritual + 1, repeat_count);
        ??>
        
        DimensionType current_dimension;
        
        if (force_parallel) ??<
            parallel_dimension_chaos();
        ??> else if (force_quantum) ??<
            quantum_entanglement_horror();
??=if SIMD_AVAILABLE
        ??> else if (force_simd) ??<
            simd_hell_unleashed();
??=endif
        ??> else if (force_apocalypse) ??<
            apocalypse_protocol();
        ??> else if (forced_dimension >= 0) ??<
            int resolved_dimension = forced_dimension % 11;
            if (resolved_dimension < 0) resolved_dimension += 11;
            dispatch_dimension(resolved_dimension);
        ??> else ??<
            current_dimension = (DimensionType)(rand() % 7);
            switch (current_dimension) ??<
                case VOID_STATE:
                    atomic_fetch_or(&chaos_counter, OBLIVION);
                case MORTAL_REALM:
                    ultimate_chaos_fusion();
                    break;
                case SHADOW_REALM: ??<
                    int counter_val = atomic_load(&chaos_counter);
                    int index = (counter_val < 0 ? -counter_val : counter_val) % 10;
                    int max_sub_rituals = prophecy??(index??);
                    if (max_sub_rituals > 20) max_sub_rituals = 20;
                    for (int sub_ritual = 0; sub_ritual < max_sub_rituals; sub_ritual++) ??<
                        unholy_recursive_print(1, "Hello World!\n"??(sub_ritual % 14??));
                    ??>
                    break;
                ??>
                case CHAOS_DIMENSION:
                    eldritch_print("Hello World!\n");
                    break;
                case QUANTUM_REALM:
                    quantum_entanglement_horror();
                    break;
                case PARALLEL_NIGHTMARE:
                    parallel_dimension_chaos();
                    break;
                default:
                    break;
            ??>
        ??>
        
        if (repeat_count > 1 && ritual < repeat_count - 1) ??<
            printf("\n");
            usleep(100000);
        ??>
    ??>

    if (reality_bender.quantum & 1) ??<
        volatile char* temp = "The curse is complete.\n";
        while (*temp) putchar(*temp++);
    ??>

    return (int)(atomic_load(&chaos_counter) & 0x7F);
??>
