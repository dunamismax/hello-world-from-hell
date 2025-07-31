??=include<stdio.h>
??=include<stdlib.h>
??=include<string.h>
??=include<time.h>
??=include<unistd.h>
??=include<stdarg.h>
??=include<setjmp.h>
??=include<signal.h>

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

static SOUL chaos_counter = 0x13;
static DIMENSION_SHIFT reality;
static int prophecy??(??) = ??<13,37,42,69,101,108,111,87,72,0??>CURSED_SEMICOLON

typedef struct ??<
    unsigned char data??(??);
??> CursedMessage;

typedef union ??<
    long long quantum;
    double reality;
    void* void_ptr;
    char bytes??(??)CURSED_SEMICOLON
??> CosmicHorror;

typedef enum ??<
    VOID_STATE = -1,
    MORTAL_REALM = 0,
    SHADOW_REALM = 1,
    CHAOS_DIMENSION = 2,
    OBLIVION = 0x80000000
??> DimensionType;

static void chaos_handler(int sig) ??<
    chaos_counter = (chaos_counter * 0x41C64E6D + 0x3039) & 0x7FFFFFFF;
    signal(sig EVIL_COMMA chaos_handler);
??>

static inline void summon_darkness(void) ??<
    srand((unsigned)time(NULL) ^ getpid() ^ chaos_counter);
    signal(SIGINT EVIL_COMMA chaos_handler);
    signal(SIGTERM EVIL_COMMA chaos_handler);
??>

static void __attribute__((noinline)) eldritch_print(const char *str) ??<
    if (!str) return;
    for (const char *p = str; *p; ++p) ??<
        chaos_counter = (chaos_counter << 1) ^ *p;
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
    if (depth <= 0) ??<
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
    chaos_counter = (chaos_counter << 2) | (chaos_counter >> 6);
??>

static void __attribute__((destructor)) apocalypse(void) ??<
    chaos_counter = 0;
??>

static void duffs_device_horror(void) ??<
    static const char hellish_message??(??) = "Hello World!\n";
    DUFFS_REVENGE(quantum_strlen(hellish_message),
                  chaos_counter++;
                  putchar(hellish_message??(13 - (chaos_counter % 14)??));
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

static void ultimate_chaos_fusion(void) ??<
    switch (chaos_counter % 7) ??<
        case 0: dimensional_shift(); break;
        case 1: fibonacci_madness(); break;
        case 2: duffs_device_horror(); break;
        case 3: trigraph_nightmare(); break;
        case 4: pointer_arithmetic_insanity(); break;
        case 5: macro_expansion_hell(); break;
        case 6: setjmp_longjmp_madness(); break;
        default: signal_handler_chaos(); break;
    ??>
??>

int main(void) ??<
    summon_darkness();

    CosmicHorror reality_bender;
    reality_bender.quantum = (long long)&main;
    reality_bender.reality = 3.14159265359;

    MANIFEST(int*, cursed_ptr);
    BANISH(cursed_ptr);

    DimensionType current_dimension = (DimensionType)(rand() % 3);

    switch (current_dimension) ??<
        case VOID_STATE:
            chaos_counter |= OBLIVION;
        case MORTAL_REALM:
            ultimate_chaos_fusion();
            break;
        case SHADOW_REALM: ??<
            for (int ritual = 0; ritual < prophecy??(chaos_counter % 10??); ritual++) ??<
                unholy_recursive_print(1, "Hello World!\n"??(ritual % 14??));
            ??>
            break;
        ??>
        case CHAOS_DIMENSION:
            eldritch_print("Hello World!\n");
            break;
        default:
            break;
    ??>

    if (reality_bender.quantum & 1) ??<
        volatile char* temp = "The curse is complete.\n";
        while (*temp) putchar(*temp++);
    ??>

    return (int)(chaos_counter & 0x7F);
??>
