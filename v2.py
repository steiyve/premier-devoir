import random

#variable de programe
quit = False
score = 0
best_score = 0
run = True

#boucle principale
while quit != True:
    
    #varialbe de la boucle
    chiffre = random.randint(0, 1000)
    repete = 0

    #loader le best_score du fichier
    with open('best.txt', 'r') as reader:
        best_score = int(reader.read())
        print(best_score)

    #boucle de jeu
    while run:

        #variable de boucle
        chiffre = random.randint(0, 1000)
        repete = 0
        reponse = int(input("entrez un chiffre entre 0 et 1000:"))
        
        #boucle qui permet d avoir 10 essai
        while repete <= 10:
            print("hallo")
            print(repete)
            # verification pour voir qui a gagne
            if (reponse == chiffre):
                print("bravo tu a gagne un point")
                score += 10 - repete
                print(score)
                break


            # mauvaise reponse
            else:
                # si le nombre choisi est plus petit
                if (reponse < chiffre):
                    print("choississez un nombre plus grand")

                # si le nombre choisi est plus grand
                if (reponse > chiffre):
                    print("choississez un nombre plus petit")
            
            reponse = int(input("entrez un chiffre entre 0 et 1000:"))
            repete += 1

    if score == best_score:
        best_score = score

    #enregistre le best_score
    with open('best.txt', 'w') as writer:
        writer.write(best_score)

    #recommencer la partie
    reponse = input("voulez vous rejouer (oui ou non):")
    if reponse == "non":
        quit == True
