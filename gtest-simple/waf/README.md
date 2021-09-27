The most difficult part about this was to recognize (by looking at the meson build result) that
googletest should not be built as a library and then linked
(can also work but creates all kinds of problems at run time, requiring manual rpath fixes and the likes).

Instead, the relevant `.cc` files are simply included in the sources for each test.

The rest, which is detecting and if necessary cloning / updating the googletest sources was easy.
