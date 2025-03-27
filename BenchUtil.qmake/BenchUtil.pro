TEMPLATE = subdirs
SUBDIRS += BenchmarkFLOPS32 
SUBDIRS += BenchmarkFLOPS64 
SUBDIRS += BenchmarkIOPS32 
SUBDIRS += BenchmarkIOPS64

BenchmarkFLOPS32.file = BenchmarkFLOPS32.pro
BenchmarkFLOPS64.file = BenchmarkFLOPS64.pro
BenchmarkIOPS32.file  = BenchmarkIOPS32.pro
BenchmarkIOPS64.file  = BenchmarkIOPS64.pro

OTHER_FILES += BenchUtil.pri

