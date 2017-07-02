<link rel="stylesheet" href="<?= WEB_ROOT ?>/modules/Candidates/css/candidates_style.css"/>
<div class="container">
    <h2>Job Candidates List</h2>  
    <?php if (!empty($this->get('slice_get_candidates'))) { ?>    
      <table id="candidates_list_table" class="table">
          <thead>      
              <tr>
                  <th>#</th>     
                  <th>Username</th>
                  <th>Gender</th>
                  <th>Age</th>
                  <th>Job Position</th>
                  <th>Internship</th>
              </tr>
          </thead>

          <tbody>      
              <?php
              $row = $this->get('paging')['row'];
              foreach ($this->get('slice_get_candidates') as $key => $data) {                
                $gender = $data['gender'] == 'm' ? 'Male' : 'Female';
                
                
                ?>
                <tr id="<?= 'candidate_' . $data['username']; ?>">
                    <td><?= $row++; ?></td>
                    <td><?= $data['username']; ?></td>
                    <td><?= $gender; ?></td>
                    <td><?= $data['age'] . ' years'; ?></td>
                    <td><?= $data['job_position']; ?></td>        
                    <td><?= $data['internship'] . ' years'; ?></td>  
                </tr>
        <?php } ?>            
          </tbody>
      </table>

      <div class="pagination">
          <?php
          for ($i = 0; $i < $this->get('paging')['max_pages']; $i++) {
            $css_class_active = "";
            if ($i == ($this->get('paging')['page'] - 1)) {
              $css_class_active = "class='active'";
            }
            ?>
            <a <?= $css_class_active ?> href="?page=<?= ($i + 1) ?>"><?= ($i + 1) ?></a>
       <?php }
       
        }else { ?>
         <div class="alert alert-danger">
              <strong>No Records!</strong>.
          </div>   
        <?php } ?>
    </div> 
</div>
