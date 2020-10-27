CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    board.h \
    dependencies/observer/observer.h \
    dependencies/observer/subject.h \
    floodit.h

SOURCES += \
    board.cpp \
    dependencies/observer/subject.cpp \
    floodit.cpp

DISTFILES += \
    dependencies/observer/doc/cppreferencetagfile/cppreference-doxygen-web.tag.xml \
    dependencies/observer/doc/cppreferencetagfile/doxywizard_configuration_externaldoc_tag.png \
    dependencies/observer/doc/html/a00001.html \
    dependencies/observer/doc/html/a00001.js \
    dependencies/observer/doc/html/a00002.html \
    dependencies/observer/doc/html/a00002.js \
    dependencies/observer/doc/html/a00003.html \
    dependencies/observer/doc/html/a00003_source.html \
    dependencies/observer/doc/html/a00004.html \
    dependencies/observer/doc/html/a00004_source.html \
    dependencies/observer/doc/html/a00005.html \
    dependencies/observer/doc/html/a00005_source.html \
    dependencies/observer/doc/html/a00006.html \
    dependencies/observer/doc/html/a00006.js \
    dependencies/observer/doc/html/a00007.map \
    dependencies/observer/doc/html/a00007.md5 \
    dependencies/observer/doc/html/a00007.svg \
    dependencies/observer/doc/html/a00008.map \
    dependencies/observer/doc/html/a00008.md5 \
    dependencies/observer/doc/html/a00008.svg \
    dependencies/observer/doc/html/a00009.map \
    dependencies/observer/doc/html/a00009.md5 \
    dependencies/observer/doc/html/a00009.svg \
    dependencies/observer/doc/html/a00010.map \
    dependencies/observer/doc/html/a00010.md5 \
    dependencies/observer/doc/html/a00010.svg \
    dependencies/observer/doc/html/a00011.html \
    dependencies/observer/doc/html/a00012.map \
    dependencies/observer/doc/html/a00012.md5 \
    dependencies/observer/doc/html/a00012.svg \
    dependencies/observer/doc/html/a00013.html \
    dependencies/observer/doc/html/a00014.map \
    dependencies/observer/doc/html/a00014.md5 \
    dependencies/observer/doc/html/a00014.svg \
    dependencies/observer/doc/html/annotated.html \
    dependencies/observer/doc/html/annotated_dup.js \
    dependencies/observer/doc/html/arrowdown.png \
    dependencies/observer/doc/html/arrowright.png \
    dependencies/observer/doc/html/bc_s.png \
    dependencies/observer/doc/html/bdwn.png \
    dependencies/observer/doc/html/classes.html \
    dependencies/observer/doc/html/closed.png \
    dependencies/observer/doc/html/doc.png \
    dependencies/observer/doc/html/doxygen.css \
    dependencies/observer/doc/html/doxygen.png \
    dependencies/observer/doc/html/dynsections.js \
    dependencies/observer/doc/html/files.html \
    dependencies/observer/doc/html/files.js \
    dependencies/observer/doc/html/folderclosed.png \
    dependencies/observer/doc/html/folderopen.png \
    dependencies/observer/doc/html/functions.html \
    dependencies/observer/doc/html/functions_func.html \
    dependencies/observer/doc/html/functions_vars.html \
    dependencies/observer/doc/html/graph_legend.html \
    dependencies/observer/doc/html/graph_legend.md5 \
    dependencies/observer/doc/html/graph_legend.svg \
    dependencies/observer/doc/html/index.html \
    dependencies/observer/doc/html/jquery.js \
    dependencies/observer/doc/html/namespaces.html \
    dependencies/observer/doc/html/namespaces.js \
    dependencies/observer/doc/html/nav_f.png \
    dependencies/observer/doc/html/nav_g.png \
    dependencies/observer/doc/html/nav_h.png \
    dependencies/observer/doc/html/navtree.css \
    dependencies/observer/doc/html/navtree.js \
    dependencies/observer/doc/html/navtreedata.js \
    dependencies/observer/doc/html/navtreeindex0.js \
    dependencies/observer/doc/html/open.png \
    dependencies/observer/doc/html/resize.js \
    dependencies/observer/doc/html/splitbar.png \
    dependencies/observer/doc/html/svgpan.js \
    dependencies/observer/doc/html/sync_off.png \
    dependencies/observer/doc/html/sync_on.png \
    dependencies/observer/doc/html/tab_a.png \
    dependencies/observer/doc/html/tab_b.png \
    dependencies/observer/doc/html/tab_h.png \
    dependencies/observer/doc/html/tab_s.png \
    dependencies/observer/doc/html/tabs.css \
    dependencies/observer/doc/observer.doxyfile \
    dependencies/observer/doc/observer_refman.pdf
