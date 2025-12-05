#include <stdio.h>
#include <string.h>
#include "../include/rift_repl.h"
#include "../include/rtrie.h"
#include "../include/consensus.h"
#include "../include/colors.h"

void rift_repl() {
    char cmd[256], arg[256];

    printf(C_GREEN "RIFT Shell Ready\n" C_RESET);

    while (1) {
        printf("rift> ");
        if (!fgets(cmd, 256, stdin)) break;

        if (sscanf(cmd, "list") == 0) {
            rtrie_print();
            continue;
        }

        if (sscanf(cmd, "scan %s", arg) == 1) {
            rtrie_scan_txt(arg);
            continue;
        }

        if (sscanf(cmd, "perm %s", arg) == 1) {
            RTrieNode *n = rtrie_find(arg);
            if (!n) printf("Not found\n");
            else printf("perm=%d\n", n->perm);
            continue;
        }

        if (sscanf(cmd, "request X %s", arg) == 1) {
            RTrieNode *n = rtrie_find(arg);
            if (!n) { printf("Not found\n"); continue; }

            if (!rtrie_request_perm(n, P_EXEC)) {
                printf(C_RED "blocked (needs consensus)\n" C_RESET);
            } else {
                rtrie_apply_perm(n, P_EXEC);
                printf(C_GREEN "granted\n" C_RESET);
            }
            continue;
        }

        if (sscanf(cmd, "consensus") == 0) {
            consensus_grant();
            printf("Consensus granted.\n");
            continue;
        }

        if (strcmp(cmd, "exit\n") == 0)
            break;
    }
}
