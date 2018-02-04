# Title: Makefile
# Date:  2016/03/03
# Name:  Yuya, Takuro

# Target file name
TARGET = thesis_master
TEX_SRCS = 	*.tex
IMG_SRCS =	../figure/*.eps			
		
# BIB file
REFDIR = ./
# REFDIR = ../../bib/
REF = $(REFDIR)/reference.bib
# CLASS File
CLS = IEEEtran.cls

# platex
PLATEX = platex
# dvipdfmx
DVIPDFMX = dvipdfmx
# pbibtex
PBIBTEX = pbibtex

# Objects
OBJS := $(TARGET).aux $(TARGET).log $(TARGET).dvi $(TARGET).toc
PDFOBJ := $(TARGET).pdf
BIBOBJS := $(TARGET).bbl $(TARGET).blg

#
# Target
#

.PHONY: all
# all: dvi adjust pdf
all: dvi pdf

.PHONY: dvi
dvi: $(OBJS)

$(OBJS): $(TARGET).tex $(REF) $(TEX_SRCS) $(IMG_SRCS)
	$(PLATEX) $(TARGET).tex
	$(PBIBTEX) $(TARGET)
	$(PLATEX) $(TARGET).tex

.PHONY: pdf
pdf: $(PDFOBJ)

$(PDFOBJ): $(TARGET).dvi $(BIBOBJS)
	$(PLATEX) $(TARGET).tex
	$(DVIPDFMX) $(TARGET).dvi

.PHONY: adjust
adjust: 
	gsed -i -e '2i ¥¥¥footnotesize' $(TARGET).bbl

.PHONY: simple
simple: 
	$(PLATEX) $(TARGET).tex
	$(PLATEX) $(TARGET).tex
	$(DVIPDFMX) $(TARGET).dvi

# 
# Optional Target
# 

.PHONY: diff
diff:
	sh latexdiff2pdf.bash $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BIBOBJS)

.PHONY: realclean
realclean:
	rm -f $(OBJS) $(BIBOBJS) $(PDFOBJ)
