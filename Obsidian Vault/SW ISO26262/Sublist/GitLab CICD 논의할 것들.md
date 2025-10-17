# OS의 종류에 따라 Ginrunner를 생성해야함.
### QAC & Codesonar
1. License : GitLab에서 사용하는 동안 각자의 Pc에서는 사용 못하는데 괜찮을까?
	1. 속도가 빠르니 큰 문제는 없어 보이지만...
2. Codesonar는 두 개의 ID중 하나는 GitLab용으로 사용하면 될 듯
3. QAC는 Window 용이고 Codesonar는 Window와 Linux 둘 다 가능하다.
4. 
### Vector Cast
1. TST 파일 자동 생성 모델을 만들어야 함.
2. TST 파일은 .c 파일 별로 만들어야 함
3. Vectorcast는 window에서 동작하므로 QNX 컴파일 방법을 논의해야 함
	1. Vectorcast에서 TST를 적용하고 결과를 Linux의 QEMU로 QNX 컴파일을 하고 결과를 Window Vectorcast에서 Execute 하여 결과를 출력한다.
	2. Window QNX를 설치하여 window에서 QEMU로 QNX 컴파일을 한다.
4. 