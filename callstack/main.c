#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

// Compile with -funwind-tables -lunwind
void backtrace() {
    printf("=== Stack trace from libunwind ===\n");

    unw_cursor_t cursor;
    unw_context_t ctx;

    // iniitlize cursor to current frame for local unwinding
    unw_getcontext(&ctx);
    unw_init_local(&cursor, &ctx);

    unw_word_t pc;
    unw_word_t sp;
    unw_word_t offset;

    char sym[256];

    // unwind frames one by one, going up the frame stack
    while (unw_step(&cursor) > 0) {
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        unw_get_reg(&cursor, UNW_REG_SP, &sp);

        if (pc == 0) {
            break;
        }

        printf("pc: 0x%lx, sp 0x%lx", pc, sp);

        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) {
          printf(" (%s+0x%lx)\n", sym, offset);
        } else {
          putchar('\n');
        }
    }
    printf("=== End ===\n\n");
}

void bar() {
  backtrace();
}

void foo() {
  bar();
}

int main() {
  foo();
  return 0;
}
