#define FROM0TO(i, len) for (i = 0; i < len; i++)
#define EACH_NODE(n, start) for (n = start; n->next != nullptr; n = n->next)