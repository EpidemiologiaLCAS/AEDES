#!/bin/bash 

if [ $# != 3 ]; then
	echo "Use: ./$0 indiceInicio indiceFim Incremento"
else
	echo "Simulacao iniciada em: $(eval "date")"
	for ((i=$1;i < $2; i+= $3)) do
		eval "cp Simulacao.bin SIMULACAO$i-$(expr $i + $3).bin"
		eval "nohup ./SIMULACAO$i-$(expr $i + $3).bin $i $(expr $i + $3) 17 > Log_MC$i-$(expr $i + $3).txt &"
		eval "sleep 1"
		eval "rm SIMULACAO$i-$(expr $i + $3).bin"
	done
	while (true) do
		i=$(eval "pstree | grep -i SIMULACAO | wc -l")
		if [ $i == 0 ]; then
			echo "Simulacao concluida em: $(eval "date")"
			exit
		fi
		echo "Faltam $i simulacoes em $(eval "date")"
		sleep 60
	done
fi

