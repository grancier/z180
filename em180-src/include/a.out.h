#ifndef A_OUT_H
#define A_OUT_H

/*
 * Format of an a.out header
 */
 
struct	exec {	/* a.out header */
	long		a_magic;	/* magic number */
	unsigned long	a_text;		/* size of text segment */
	unsigned long	a_data;		/* size of initialized data */
	unsigned long	a_bss;		/* size of uninitialized data */
	unsigned long	a_syms;		/* size of symbol table */
	unsigned long	a_entry;	/* entry point */
	unsigned long	a_trsize;	/* size of text relocation */
	unsigned long	a_drsize;	/* size of data relocation */
};

#define	A_MAGIC1	0407		/* normal */
#define	A_MAGIC2	0410		/* read-only text */
#define	A_MAGIC3	0411		/* separated I&D (not on VAX) */
#define	A_MAGIC4	0405		/* overlay */
#define	A_MAGIC5	0413		/* demand page read-only text */

/* does struct exec x have a bad magic number? */
#define	N_BADMAG(x) \
    ((x).a_magic!=A_MAGIC1 && (x).a_magic!=A_MAGIC2 && (x).a_magic!=A_MAGIC5 && \
     (x).a_magic!=A_MAGIC4)

/* has the executable file been stripped? */
#define	N_STRIP(x) \
    ((x).a_syms == 0 && (x).a_trsize == 0 && (x).a_drsize == 0)

/* mark an object file as having no relocation information */
#define	N_NOREL(x)  (((x).a_trsize = 0), ((x).a_drsize = 0))

/* file offsets for object file sections */
#define	N_TXTOFF(x) ((x).a_magic==A_MAGIC5 ?1024L: (long)sizeof(struct exec))
#define	N_DATOFF(x) (N_TXTOFF(x) + (long)(x).a_text)
#define	N_TXTREL(x) (N_DATOFF(x) + (long)(x).a_data)
#define	N_DATREL(x) (N_TXTREL(x) + (long)(x).a_trsize)
#define N_SYMOFF(x) (N_DATREL(x) + (long)(x).a_drsize)

struct relocation_info {
	  long  r_address;	/* relative to current segment */
	  unsigned	r_symbolnum:24,
				/* if extern then symbol table */
				/* ordinal (0, 1, 2, ...) else */
				/* segment number (same as symbol types) */
	        r_pcrel:1, 	/* if so, segment offset has already */
				/* been subtracted */
	  	r_length:2,	/* 0=byte, 1=word, 2=long */
	  	r_extern:1,	/* does not include value */
				/* of symbol referenced */
		r_perm:2,	/* permutation of bytes in short/long */
		r_unsign:1,	/* =1, offset is unsigned */
		:1;
};

/* for portability the following are used, instead of the above */
#define	R_REL(l) ((l)>>24)
#define	R_SYM(l) ((l)&~(-1<<24))
#define	R_MAKE(r,s) (((long)((r)&0377)<<24)|(s))
#define	R_PCREL	01
#define	R_LEN(x) ((x)&06)
#define	R_LEN1	0
#define	R_LEN2	2
#define	R_LEN4	4
#define	R_EXT	(01<<3)
#define	R_PERM(x) (((x)>>4)&03)
#define	R_UNSIGN (01<<6)

struct	nlist { /* symbol table entry in memory */
	char	*n_name;	/* for use in main store */
	char	n_type;		/* relocation type (segment) */
	char	n_class;	/* storage class */
	unsigned short n_ctype;	/* C type */
	unsigned long n_value;	/* value */
};

struct	syment {	/* symbol table entry from file */
	char	n_type;	/* relocation type */
	char	n_class;	/* storage class */
	unsigned short n_ctype;	/* C type */
	unsigned long n_value;	/* value */
};
/* this is optionally followed by a null-terminated name (see N_NAME) */

/* compatibility: */
#define	n_other	n_class
#define	n_desc	n_ctype

	/* values for type flag */
#define	N_UNDF	0		/* undefined */
#define	N_ABS	02		/* absolute */
#define	N_TEXT	04		/* text */
#define	N_DATA	06		/* data */
#define	N_BSS	010
#define	N_COMM	014		/* common (used internally by ld(1)) */
#define	N_FN	016		/* file name symbol */
#define	N_TYPE	016

#define	N_EXT	01		/* external bit, or'ed in */
#define	N_NAME	040		/* null-terminated name follows syment */

#define	N_MAXNM	150		/* longest supported name */

#define	FORMAT	"%.8x"



#endif /* A_OUT_H */

