readFloat:
	addi	$sp,	$sp,	-4
	sw	$ra,	0($sp)
	li	$v0,	7
	syscall
	mfc1.d	$v0,	$f0
	lw	$ra,	0($sp)
	addi	$sp,	$sp,	4
	jr $ra
