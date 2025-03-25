#O(n)
def prob1(str):
   return max(str.split(" "))
   
def prob1_ai(text):
   cuvinte = text.split()  # Împărțim textul în cuvinte
   maxim = ""  # Inițializăm cuvântul maxim

   for cuvant in cuvinte:
        if cuvant > maxim:  # Comparare alfabetică
            maxim = cuvant
    
   return maxim

print(prob1_ai("ana are mere si prune"))
print(prob1("ana are mere si prune"))

