	xdef	_ikbd_isr
	xref	_do_ikbd_isr

_ikbd_isr:
	movem.l	d0/a0,-(sp)
	jsr	_do_ikbd_isr
	movem.l	(sp)+,d0/a0
	rte
