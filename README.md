Braço robótico com garra

Equipamentos utilizados:

1 Fonte chaveada colmeia manual 5V 20A 100W Bivolts
1 Fonte 12V para Arduino Uno R4 Mínima
1 Botão interruptor start reset com capa pulso segredo com fio
3 Extensão de Servo JR/Futaba
1 Arduino Uno R4 Mínima - alimentado pela Fonte 12V para Arduino Uno R4 Mínima
1 Módulo PCA9685 - O V+ e GND será alimentado pela fonte colmeia com 6V e a alimentação do chip é alimentado pela saída de 5V do Arduino 
5 Servo Motor MG996R 180° 11kg/cm Com Engrenagem Metálica - alimentados pela fonte colmeia usando saídas de 6V e GND cada um usando a Extensão de Servo JR/Futaba
1 Garra em alumínio usando um dos 5 Servo Motor MG996R 180° 11kg/cm Com Engrenagem Metálica
4 Conector WAGO Emenda 5 Fios 20A
3 Conector WAGO Terminal 2 Polos 20A
4 Jumper Fio Macho/fêmea Para Arduino (Vermelho, Preto, Cinza, Laranja)
1 Base Prato Giratório Redondo 20cm Em Alumino
1 Kit multifuncional de montagem de cabeça de direção de servomotor para acessórios robóticos
3 Fios de 1,5mm (Verde, Branco, Amarelo) para Extensão que liga a fonte colmeia na tomada - Conector WAGO Terminal 2 Polos 20A
2 Fios de 1,5mm (Branco, Amarelo) para ligar os motores e o Módulo PCA9685 na fonte colmeia - Conector WAGO Emenda 5 Fios 20A

Observação: todos os servo motor são alimentados por uma fonte colmeia com saídas 6V e GND ligados usando Extensão de Servo JR/Futaba

Os movimentos serão:

1°  Move o motor da Base para 90° e os demais motores para a posição 0°
2°  Move o motor da Base de 90° para 0°
3°  Move o motor da Garra para 45°
4°  Move o motor do Pulso para 45°
5°  Move o motor do Cotovelo para 45°
6°  Move o motor do Ombro para 30°
7°  Move o motor da Garra para 82° (Pega a caixa na origem)
8°  Move o motor do Pulso para 25°
9°  Move o motor da Base de 0° para 180°
10° Move o motor da Pulso para 42°
11° Move o motor da Garra para 45° (Deixa a caixa no destino)
12° Move o motor do Pulso para 25°

13° Movimenta todos os motores de sua posição atual ate a posição inicial na ordem a seguir:
	1° Ombro move ate 0°
	2° Cotovelo move ate 0°
	3° Pulso move ate 0°
	4° Garra move ate 90°
	5° Base move ate 90°
