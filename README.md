CONTROLES
JUGADOR: X para activar y desactivar el jetpack
		B para disparar desde la camara(proyectil tipo 1)
		V para disparar desde la camara(proyectil tipo 2)
FUERZAS: G para activar y desactivar la gravedad
	 L para activar y desactivar el viento de izquierda
	 R para activar y desactivar el viento de derecho

Apartados de a entregar
A)
A.1 metodos de integracion vistos en clase.
	Esto se encuentra en clase Particle.cpp en el método integrate(double t) línea 82.
A.2 Masa como parámetro.
	La constructora de la clase Particle recibe un parámetro de masa . Archivo Particle.cpp línea 26. En la practica hay dos particulas definidas con masas distintas.(Las siguiente líneas pertenecen a las constructoras de ParticlesGenerators que luego se encargan de generar las particulas llamando, a su vez al EntityManager que se encarga de generar la entidad(EntityManager.cpp línea 41)) Archivos donde se crean los generators que crean las partículas.
		-GameScene.ccp línea 35 (en el uniformGenerator)
		-PlayerEntity.cpp línea 15 (En el GausianGenerator)
A.3 Gestión de Fuerzas y aceleraciones teniendo en cuenta la masa.
	El calculo de las fuerzas lo gestionan las propias partículas consultando en su lista punteros a los ForceGenerator que le afectan si tiene que aplicar fuerza y cuanta deben aplicar sobre la particula
		-La consulta y calculo se comprueba en el metodo AddForces() Archivo Particle.cpp línea 103.
		Los calculos de las fuerzas a aplicar se hacen dentro de los generadores en el método addForceToParticle() (NOTA en el codigo se distingue entre partículas y la entidad del jugador ya que todavia falta toda la lógica de solido rígidos).
		 Archivo ForceGenerator.cpp línea 19 (y en los override del método en generadores como windGenerator).
B) Implementación de la clase proyectil.
	Esta lógica se encuentra en la clase Bullet.cpp y Bullet.h. Pero dados los cálculos que se realizan dentro de Particle esta clase ha quedado obsoleta desde la practica 2 ya que las partículas también cuentan con masa y aun no tenemos proyectiles con volumen real en la practica.

C)  Sistema de Partículas
	Este apartado se encuentra en la clase ParticleSystem(.h/.cpp) que se encarga de guardar una lista de ParticleGenerator y modificar la posición de inicio de estos o los generadores de fuerzas que afectan a estas a las partículas de este sistema.
D) Generadores de partículas
	Los ParticleGenerator se encargan de guardar la información requerida las variaciones de estas de las partículas a generar y de generar estas. Esto se puede ver en la clase de mismo nombre y en las clases que heredan de esta como GaussianGenerator(.h/.cpp)  y UniformGenerator(.h/.cpp).
D.1 
	Como he mencionado anteriormente mis generadores son un poco mas complejos al no pasar una partícula modelo si no pasar todos los parámetros y el máximo de variabilidad en estos desde la constructora de la clase Generator. línea 4
D.2
	Las clases GausianGenerator y UniformGenerator generan las particulas en posiciones variables respecto al origen. Con la adición de una variación en la velocidad inicial o el color (Método generateParticle()). 
D.3
	Como se ha mencionado anteriormente la clase ParticleSystem posee una lista de los generadores de partículas que queremos crear dentro de la instancia de esta clase los generadores y sistemas se pueden activar y desactivar con sus sus métodos setActive().

E) Generador de Fuerza
E.1 Cálculo de fuerza se realiza de manera independiente
	Véase en la llamada ya mencionada en el addForces() de las entidades que llama al addForceToPArticle() del generador de fuerzas.
E.2 Cada partícula puede recibir fuerzas de más de un Generador de Fuerzas.
	 Como se ha mencionado anteriormente las propias entidades poseen una lista de punteros a los generadores que la afectan. Archivo Entity.h línea 13.
E.3 Cada Sistema de Partículas C) llevará un registro de los Generadores de Fuerzas
	Cada sistema de partículas guarda una lista de los generadores de fuerzas que posee. Este le pasa dicha lista de punteros a los ParticleGenerator y estos a las partículas.  Los generadores de fuerzas son creados en las escenas(menos en el caso del Player ya que solo él se ve afectado  por la fuerza ascendente del jetpack y las partículas que genera por una fuerza descendente)
		Archivo ParticleSystem método addGenForce() y ParticleGenerator método addForceGen();
E.4 dos tipos de generadores de fuerza. 
	En la clase GameScene encotramos un generador de gravedad, y dos generadores de viento donde leftWind aumenta de intensidad con el tiempo. Archivos GravityForceGen y WindTimeGenerator.
	