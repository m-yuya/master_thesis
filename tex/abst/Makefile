# Title: Makefile
# Date:  2016/03/03
# Name:  Yuya, Takuro

# Target file name
TARGET = abstract
TEX_SRCS = 	*.tex
			
# platex
PLATEX = platex
# dvipdfmx
DVIPDFMX = dvipdfmx
# pbibtex
PBIBTEX = pbibtex

# Objects
OBJS := $(TARGET).aux $(TARGET).log $(TARGET).dvi $(TARGET).toc
PDFOBJ := $(TARGET).pdf

#
# Target
#

.PHONY: all
all: dvi pdf
# all: dvi adjust pdf

.PHONY: dvi
dvi: $(OBJS)

$(OBJS): $(TARGET).tex $(TEX_SRCS)
	$(PLATEX) $(TARGET).tex
	$(PLATEX) $(TARGET).tex

.PHONY: pdf
pdf: $(PDFOBJ)

$(PDFOBJ): $(TARGET).dvi
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
