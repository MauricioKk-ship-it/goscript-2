;; Module File System pour GoScript
(let fs (quote ()))

(= read (fn (path) 
  (fs/read-file path)))

(= write (fn (path content) 
  (fs/write-file path content)))

;; On retourne une liste de fonctions ou l'objet fs
(print "Module FS chargé avec succès")
