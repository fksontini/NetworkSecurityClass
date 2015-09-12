<?php
	/* M Abdessabour Arous */
	/* Adapted from DVWA code */
	
	if (isset($_POST['Upload'])) {

			$target_path = "/var/www/pdf/";
			$target_path = $target_path . basename( $_FILES['uploaded']['name']);
			echo $target_path;

			if(!move_uploaded_file($_FILES['uploaded']['tmp_name'], $target_path)) {
				echo '<p>Votre CV n\'a pas pu être uploader.</p>';
      		} else {
				echo '<p>'.$target_path . ' CV uploader avec succès!<p>';	
			}
		}
?>